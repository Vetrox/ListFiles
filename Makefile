windows: ./src/main.cpp
	g++.exe -std=c++17 -O3 -o ./bin/ListFiles_windows.exe ./src/main.cpp 

windows_static_deploy: ./src/main.cpp
	x86_64-w64-mingw32-g++.exe -std=c++17 -O3 -static -o ./bin/ListFiles_windows_static.exe ./src/main.cpp 

linux: ./src/main.cpp
	g++ -std=c++17 -O3 -o ./bin/ListFiles_linux ./src/main.cpp -pthread

linux_static_deploy: ./src/main.cpp
	g++ -std=c++17 -O3 -static -o ./bin/ListFiles_linux_static ./src/main.cpp -pthread
