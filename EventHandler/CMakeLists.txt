
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${PROJECT_PATH}/com)
#include_directories(${PROJECT_PATH}/EventHandler)

add_library(com.cpp event_handler.cpp)

set_target_properties(event_handler_lib PROPERTIES OUTPUT_NAME "event_handler_lib")

