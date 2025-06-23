
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_PATH}/sqlite)
include_directories(${PROJECT_PATH}/database)


add_library(database_lib database.cpp  libsqlite3.so  -lsqlite3)

set_target_properties(database_lib PROPERTIES OUTPUT_NAME "database_lib")



