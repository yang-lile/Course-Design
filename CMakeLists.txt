cmake_minimum_required(VERSION 3.17)
project(store_system)

set(CMAKE_CXX_STANDARD 20)

include_directories(modules)

add_subdirectory(modules/interface)
add_subdirectory(modules/model)
add_subdirectory(modules/data_struct)

aux_source_directory(modules/interface dir_interface)
aux_source_directory(modules/model dir_model)
aux_source_directory(modules/data_struct dir_data_struct)

add_executable(store_system
        src/main.cpp
        ${dir_interface}
        )

target_link_libraries(store_system interface)
target_link_libraries(store_system model)
target_link_libraries(store_system data_struct)

# FixedString测试的子模块
project(fixed_string)

add_executable(fixed_string
        src/test/fixed_string_test.cc
        modules/data_struct/fixed_string.cc
        modules/data_struct/fixed_string.h
        ${dir_interface}
        )

target_link_libraries(fixed_string interface)


# Goods测试的子模块
project(goods)

add_executable(goods
        modules/model/goods.cc
        modules/model/goods.h
        modules/data_struct/fixed_string.cc
        modules/data_struct/fixed_string.h
        ${dir_interface}
        src/test/goods.cc)

target_link_libraries(goods interface)
