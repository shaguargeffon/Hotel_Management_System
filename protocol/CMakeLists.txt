
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})


#include_directories(${PROJECT_PATH}/types)
#include_directories(${PROJECT_PATH}/handler)
#include_directories(${PROJECT_PATH}/protocal)

#include_directories(${PROJECT_PATH}/com)
include_directories(${PROJECT_PATH}/protocol)

add_library(protocol_lib protocol.cpp)

set_target_properties(protocol_lib PROPERTIES OUTPUT_NAME "protocol_lib")



