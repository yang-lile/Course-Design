aux_source_directory(. dir_data_struct)
add_library(data_struct ${dir_data_struct} link_list.cc link_list.h)