
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_PATH}/sqlite)

add_library(database_lib database.cpp)

set_target_properties(database_lib PROPERTIES OUTPUT_NAME "database")
