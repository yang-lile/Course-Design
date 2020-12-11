aux_source_directory(. dir_data_struct)
add_library(data_struct SHARED ${dir_data_struct})
# 连上隔壁动态链接库
target_link_libraries(data_struct interface)