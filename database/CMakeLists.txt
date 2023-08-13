
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

//include_directories(${PROJECT_PATH}/frame)
include_directories(${PROJECT_PATH}/database)

add_library(database_lib libdatabase.a database.cpp -lsqlite3)

set_target_properties(database_lib PROPERTIES OUTPUT_NAME "database_lib")
