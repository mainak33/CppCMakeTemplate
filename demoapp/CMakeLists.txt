# Works with 3.14 and tested through 3.26
cmake_minimum_required(VERSION 3.16...3.26)

# Project name and a few useful settings. Other commands can pick up the results
project(
  demoapp
  VERSION 1.0.0)

add_executable(demoapp demoapp.cpp)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/../install")
find_package(demolib REQUIRED)
target_link_libraries(demoapp PRIVATE demolib::demolib)
