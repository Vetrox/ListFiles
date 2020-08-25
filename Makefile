autorun: ./src/main.cpp
	g++.exe -std=c++17 -O3 -o ./build/ListFiles.exe ./src/main.cpp 

static_deploy_only: ./src/main.cpp
	x86_64-w64-mingw32-g++.exe -Wall -std=c++17 -O3 -static -o ./build/ListFiles.exe ./src/main.cpp 