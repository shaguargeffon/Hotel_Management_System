
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#include_directories(${PROJECT_PATH}/sqlite)
include_directories(${PROJECT_PATH}/types)
include_directories(${PROJECT_PATH}/database)
#include_directories(${PROJECT_PATH}/database/thirdparty/SQLiteCpp)

add_library(service_lib service.cpp)

set_target_properties(service_lib PROPERTIES OUTPUT_NAME "service")
