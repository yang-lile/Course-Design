aux_source_directory(. dir_tools)
add_library(
        tools SHARED STATIC
        ${dir_tools}
        assist.cc
        file_operations.cc
        output_template.h
        output_template.cc
)