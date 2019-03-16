cmake_minimum_required(VERSION 3.4)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(helloworld src/application.cpp)
target_include_directories(helloworld PRIVATE include)