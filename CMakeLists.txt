cmake_minimum_required(VERSION 3.17)
project(store_system)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(modules/interface)
add_subdirectory(modules/model)

aux_source_directory(modules/interface dir_interface)
aux_source_directory(modules/model dir_model)

add_executable(store_system
        src/main.cpp
        ${dir_interface}
        modules/model/goods.cc modules/model/goods.h)

target_link_libraries(store_system interface)
target_link_libraries(store_system model)
