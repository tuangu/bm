cmake_minimum_required(VERSION 3.4)
project(bank_management CXX)

if (MSVC)
    add_compile_options(/W4 /w44265 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(${PROJECT_NAME} src/main.cpp src/application.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE include)

#
# Build the tests
#

add_subdirectory(Catch2)

add_executable(tests test/test_application.cpp src/application.cpp)

target_include_directories(tests PRIVATE include)
target_link_libraries(tests Catch2::Catch2)