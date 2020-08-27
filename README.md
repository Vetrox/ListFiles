# ListFiles
Listing the number of files across each subordinate path in a filesystem is made easy. This tool allows you to search for huge clusters of files by the given filetype and returns a list of paths sorted by the number of found entries in it. 

## An example usage
Let's say you want to search for all kind of images in your old copy of your previous system. You don't know where you might have stored some images. Then you run the following command in the directory you want to start your search from.
```
alice@system:~/copy_of_old_system$ /home/alice/ListFiles/bin/ListFiles_linux_static png jpg mov heic
RUNNING!
DONE!
    1001 File(s) in /home/alice/copy_of_old_system/Users/alice/AppData/LocalLow/company/PhotoSaver/pictures/
```

## Windows
Get the ListFiles_windows_static.exe (in the bin folder) from this repository by e.g. cloning or forking it. Execute the exe in the desired folder for search followed by a list of arguments which are the filetypes to search for.
```
C:\> %homepath%\ListFiles_static.exe png jpg mov heic
```

## Linux
Get the ListFiles_linux_static (in the bin folder) from this repository by e.g. cloning or forking it. Execute the executable in the desired folder for search followed by a list of arguments which are the filetypes to search for.
```
alice@system:~/ListFiles_linux_static png jpg mov heic
```

## Build Your Own Copy
Get yourself some kind of c++ compiler (for example g++) (minimum c++ standard support should be c++17, so get the newest version) and run the make file followed by linux for linux and windows for windows. You might need to replace 'g++' in the makefile with the path to your compiler or just its name. Now you get a binary, that doesn't have the '_static' at the end of the filename.
