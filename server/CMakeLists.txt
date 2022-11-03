
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

message("The directory is: " ${PROJECT_PATH})

include_directories(${PROJECT_PATH}/handler)
include_directories(${PROJECT_PATH}/sqlite)

add_library(server_lib server.cpp)

set_target_properties(server_lib PROPERTIES OUTPUT_NAME "server_lib")
