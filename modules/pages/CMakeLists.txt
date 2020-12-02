aux_source_directory(. dir_pages)
add_library(pages ${dir_pages} administrator/admin_login.cc seller/seller_login.cc shopkeeper/shopkeeper_login.cc)