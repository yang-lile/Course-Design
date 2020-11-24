cmake_minimum_required(VERSION 3.17)
project(store_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(modules/interface)

aux_source_directory(modules/interface dir_interface)

add_executable(store_system
        src/main.cpp
        ${dir_interface}
        )

target_link_libraries(store_system interface)