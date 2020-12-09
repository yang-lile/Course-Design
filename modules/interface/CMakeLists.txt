aux_source_directory(. dir_interface)
add_library(
        interface
        SHARED # 动态链接库
        STATIC # 静态链接库
        ${dir_interface}
        clean_interface.h
        data_struct_interface.h
        display_interface.h
        empty_interface.h
        insert_interface.h
        length_interface.h
        remove_interface.h
        modify_interface.h
        search_interface.h
        find_interface.h
        list_interface.h)