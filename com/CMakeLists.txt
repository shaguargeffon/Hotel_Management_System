
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

message("The directory is: " ${PROJECT_PATH})

#include_directories(${PROJECT_PATH}/types)


include_directories(${PROJECT_PATH}/FrameHandler)
include_directories(${PROJECT_PATH}/protocal)
include_directories(${PROJECT_PATH}/com)


add_library(com_lib com.cpp)

set_target_properties(com_lib PROPERTIES OUTPUT_NAME "com_lib")
