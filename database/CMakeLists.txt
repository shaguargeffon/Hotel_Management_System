include_directories(${PROJECT_PATH}/sqlite)

include_directories(include )

add_library(database_lib ./src/database.cpp )

target_link_libraries(database_lib ../sqlite/libsqlite3.so)

set_target_properties(database_lib PROPERTIES OUTPUT_NAME "database_lib")

add_subdirectory(test)
