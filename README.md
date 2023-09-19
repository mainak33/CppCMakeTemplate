# Description
Template Repository for development in C++ with Cmake. Basic functionality is explained below. Modify the CMakefiles as needed to make adjustments for larger projects

# Prerequisites
CMAKE version 3.16 or higher

# Directory structure
- Subdirectory demolib contains a demo C++ library  with a single interface answerToTheUltimateQuestionOfLifeTheUniverseAndEverything
- Subdirectory demoapp contains a demp application which uses this libary interface with #include <demolib/demolib.h>
- Subdirectory test contains code to test this interface
- The project also contains a Dockerfile showing how to build the library inside a docker container

# Functionality
Issue commands in the project parent folder
## Building 
```
$ cmake -S . -B build
$ cmake --build build
```
## Installing libdemo
```
cmake --install build --prefix install 
```
will install the library libdemolib.a at ./install/lib/ and the demolib includes at /install/include/demolib/demolib. The demoapp in build/demoapp consumes this library.
## Running the demoapp
```
$ ./build/demoapp/demoapp 
```
## Running the tests
```
$ ./build/test/demolibTests --gtest_output="xml:testreport.xml"
```
