# cmake声明
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 20)

# FixedString测试的子模块
project(fixed_string)

add_executable(
        fixed_string
        src/test/fixed_string_test.cc
        modules/data_struct/fixed_string.cc
        modules/data_struct/fixed_string.h
        ${dir_interface}
)

target_link_libraries(fixed_string interface)


# Goods测试的子模块
project(goods)

add_executable(
        goods
        src/test/goods.cc
        modules/model/goods.cc
        modules/model/goods.h
        modules/data_struct/fixed_string.cc
        modules/data_struct/fixed_string.h
        ${dir_interface}
)

target_link_libraries(goods interface)

# administrator输入输出测试模块
project(administrator)

add_executable(
        administrator
        modules/data_struct/fixed_string.cc
        modules/data_struct/fixed_string.h
        modules/model/administrator.cc
        modules/model/administrator.h
        ${dir_interface}
        src/test/administrator_test.cc)

target_link_libraries(administrator interface)
file(COPY resource/Admin.txt DESTINATION resource/)

# 主程序
project(store_system)

include_directories(modules)

add_subdirectory(modules/interface)
add_subdirectory(modules/model)
add_subdirectory(modules/data_struct)
add_subdirectory(modules/tools)
add_subdirectory(modules/pages)

add_executable(store_system
        src/main.cpp
        )

# 链接顺序很重要
target_link_libraries(store_system data_struct)
target_link_libraries(store_system model)
target_link_libraries(store_system tools)
target_link_libraries(store_system pages)
target_link_libraries(store_system interface)

# 资源文件拷贝
file(COPY resource/Admin.txt DESTINATION resource/)

