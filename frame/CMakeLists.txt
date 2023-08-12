
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_PATH}/frame)
include_directories(${PROJECT_PATH}/EventHandler)

add_library(frame_lib event_handler.cpp frame.cpp)

set_target_properties(frame_lib PROPERTIES OUTPUT_NAME "frame_lib")
