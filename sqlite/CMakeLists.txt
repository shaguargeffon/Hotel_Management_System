
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})


include_directories(${PROJECT_PATH}/sqlite)

add_library(sqlite_lib sqlite3.c)

set_target_properties(sqlite_lib PROPERTIES OUTPUT_NAME "sqlite_lib")
