
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#include_directories(${PROJECT_PATH}/types)

#include_directories(${PROJECT_PATH}/protocal)
#include_directories(${PROJECT_PATH}/com)

include_directories(${PROJECT_PATH}/frame)
include_directories(${PROJECT_PATH}/FrameHandler)

#add_library(com_lib com_tcpip.cpp)
#add_library(protocal_lib protocal_tcpip.cpp)
add_library(frame_lib frame.cpp)
add_library(frame_handler_lib frame_handler.cpp)


set_target_properties(frame_handler_lib PROPERTIES OUTPUT_NAME "frame_handler_lib")
