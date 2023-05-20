enable_testing()

add_executable(demolibTests test.cpp)

find_package(demolib REQUIRED)
target_link_libraries(demolibTests PRIVATE 
                    demolib::demolib 
                    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(demolibTests)
