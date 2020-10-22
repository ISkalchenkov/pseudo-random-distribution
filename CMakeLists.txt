cmake_minimum_required(VERSION 3.10)

project(prd)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_SRCS
        "src/main.cpp"
        "src/utils.cpp")

add_executable(prd ${PROJECT_SRCS})
target_include_directories(prd PUBLIC include)

