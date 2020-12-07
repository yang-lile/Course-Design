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


## Goods测试的子模块
#project(goods)
#
#add_executable(
#        goods
#        modules/model/goods.cc
#        modules/model/goods.h
#        modules/data_struct/fixed_string.cc
#        modules/data_struct/fixed_string.h
#        ${dir_interface}
#        src/test/goods_test.cc)
#
#target_link_libraries(goods interface)

## administrator输入输出测试模块
#project(administrator)
#
#add_executable(
#        administrator
#        src/test/administrator_test.cc
#        modules/systems/administrator/admin_login.cc
#        modules/model/login_system.cc
#        modules/model/login_system.h
#        modules/data_struct/fixed_string.cc
#        modules/data_struct/fixed_string.h
#        modules/interface/length_interface.cc
#        modules/interface/length_interface.h
#        modules/interface/base_interface.cc
#        modules/interface/base_interface.h
#        modules/model/output_template.cc
#        modules/model/output_template.h
#        modules/model/user_message.cc
#        modules/model/user_message.h
#)
#
#target_link_libraries(administrator data_struct)
#target_link_libraries(administrator tools)
#target_link_libraries(administrator systems)
#target_link_libraries(administrator interface)
#target_link_libraries(administrator model)
#
#file(COPY resource/Admin.txt DESTINATION resource/)

# 主程序
project(store_system)

include_directories(modules)

add_subdirectory(modules/systems)
add_subdirectory(modules/model)
add_subdirectory(modules/interface)
add_subdirectory(modules/data_struct)
#add_subdirectory(modules/tools)

add_executable(
        store_system
        #        src/main.cpp
        src/test/administrator_test.cc
)

# 链接顺序很重要
target_link_libraries(
        store_system
        systems
        model
        data_struct
        interface
)
#target_link_libraries(store_system data_struct)
#target_link_libraries(store_system model)
#target_link_libraries(store_system systems)
#target_link_libraries(store_system tools)

# 资源文件拷贝
file(COPY resource/Admin.txt DESTINATION resource/)
