
string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#message("The directory is: " ${PROJECT_PATH})

include_directories(${PROJECT_PATH}/service)


add_library(service_manager_lib service_manager.cpp)

set_target_properties(service_manager_lib PROPERTIES OUTPUT_NAME "service_manager_lib")


#target_link_libraries(service_manager_lib PRIVATE service_lib)
