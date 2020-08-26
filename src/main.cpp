#include <iostream>
#include <filesystem>
#include <algorithm>
#include <future>
#include <mutex>
#include <queue>
#include <unordered_set>

std::string get_current_dir() {
    return std::filesystem::current_path().string();
}

static std::mutex m;
static std::mutex outm;
static std::mutex aom;
static std::unordered_set<std::string> mask;

static std::vector<std::pair<int, std::string>> map;
static std::queue<std::shared_future<void>> ao;

void listFiles(const std::string path);

void print(std::string s) {
    std::lock_guard<std::mutex> lk(outm);
    std::cout << s << std::endl;
}


void exec(std::string path) {
    std::lock_guard<std::mutex> lk(aom);
    ao.push(std::async(std::launch::async, listFiles, path));
}


void listFiles(const std::string path) {
    int nr_of_images = 0;

    for (const auto& entry : std::filesystem::directory_iterator(path, std::filesystem::directory_options::skip_permission_denied)) {
        if (entry.is_directory()) {
            exec(entry.path().string());
        } else {
            std::string name = entry.path().string().substr(path.length());
            std::string ext = name.substr(name.find_last_of(".")+1);
            if(mask.find(ext) != mask.end()) nr_of_images++;
        }
    }

    if(nr_of_images > 0){
        std::lock_guard<std::mutex> lk(m);
        map.push_back({nr_of_images, path});  
    }
}

void updater() {
    while (true) {
        aom.lock();
        size_t ao_s = ao.size();
        aom.unlock();
        if (ao_s == 0) return;
           
        for (size_t i = 0; i < ao_s; i++) {
            ao.front().wait();
            aom.lock();
            ao.pop();
            aom.unlock();
        }
    }
}

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; i++) {
        std::string str(argv[i]);
        mask.insert(str);
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        mask.insert(str);
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        mask.insert(str);
    }
    
    std::string cwd = get_current_dir();
    print("WORKING at " + cwd);
    listFiles(cwd);
    std::thread e(updater);
    e.join();
    std::cout << "DONE!\n";
    std::sort(map.begin(), map.end());
    for (const auto& [value, key] : map) {
        std::string ret = std::to_string(value) + " File(s) in ";
        std::cout << std::setw(20) <<ret << key << std::endl;
    }
}
