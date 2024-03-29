# Cmake versions
cmake_minimum_required(VERSION 3.16...3.26)

# Project name and a few useful settings.
project(
  CppCMakeTemplate
  VERSION 0.1
  LANGUAGES CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)

# In case external pre-build libbraries they must be put inside the CMAKE_PREFIX_PATH
set(CMAKE_PREFIX_PATH "/prefix")
set(as_subproject demolib)
# Make find_package a no op for execiutables/libraries internal to the Messaging Challenge project 
macro(find_package)
    message(STATUS "${ARGV0}")
    if(NOT "${ARGV0}" IN_LIST as_subproject)
        _find_package(${ARGV})
    endif()
endmacro()

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)

    # FetchContent added in CMake 3.11, downloads during the configure step
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    
    # Turn off installing of gtest and gmock along with messages library
    option(INSTALL_GMOCK OFF)
    option(INSTALL_GTEST OFF)
    
    # FetchContent_MakeAvailable was added in CMake 3.14; simpler usage
    FetchContent_MakeAvailable(googletest)
endif()

# The demolibrary code is here
add_subdirectory(demolib)

# The demoapp code is here
add_subdirectory(demoapp)

# The testing code is here
add_subdirectory(test)