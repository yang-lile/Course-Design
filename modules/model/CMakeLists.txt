aux_source_directory(. dir_model)
add_library(model SHARED ${dir_model})

# 链接动态链接库
target_link_libraries(model data_struct interface tools)