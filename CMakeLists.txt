cmake_minimum_required(VERSION 3.10)

project(main)

set(CMAKE_CXX_STANDARD 17)

find_package(args CONFIG REQUIRED)

add_executable(main
    main.cpp
)

target_link_libraries(main PRIVATE taywee::args)