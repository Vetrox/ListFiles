# ListFiles
listing the number of files across each subordinate path in a filesystem is made easy. This tool allows you to search for huge clusters of files by the given filetype and returns a list of paths.

## Usage
Get the ListFiles.exe from this repository by e.g. cloning or forking it. Execute the exe in the desired folder for search followed by a list of arguments which are the filetypes to search for.

### Example
C:\> %homepath%/ListFiles.exe png jpg mov heic



## Build (ONLY, TO VERYFY MY BUILDS)
Get yourself g++ (minimum support should be c++17) and run the make file. Replace the compiler in the makefile with your instance. Currently it uses the mingw offered by cygwin.
