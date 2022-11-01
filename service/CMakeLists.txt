
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

message("The directory is: " ${PROJECT_PATH})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../service)




add_library(service_lib service.cpp)

set_target_properties(service_lib PROPERTIES OUTPUT_NAME "service_lib")











