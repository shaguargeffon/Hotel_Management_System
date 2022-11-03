
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#include_directories(${PROJECT_PATH}/sqlite)
include_directories(${PROJECT_PATH}/database)

add_library(handler_lib handler.cpp)

set_target_properties(handler_lib PROPERTIES OUTPUT_NAME "handler")
