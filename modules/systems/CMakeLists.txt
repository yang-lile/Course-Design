aux_source_directory(. dir_systems)
aux_source_directory(./administrator dir_systems_admin)
aux_source_directory(./seller dir_system_seller)
aux_source_directory(./shopkeeper dir_system_shopkeeper)
add_library(
        systems
        SHARED
        ${dir_systems_admin}
        ${dir_system_seller}
        ${dir_system_shopkeeper}
        ${dir_systems}
)
target_link_libraries(systems model data_struct interface)