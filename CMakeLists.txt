cmake_minimum_required(VERSION 3.0)

project(HOTEL)

#include_directories(${PROJECT_SOURCE_DIR}/hotel)
#include_directories(${PROJECT_SOURCE_DIR}/protocal)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/server)
#include_directories(${PROJECT_SOURCE_DIR}/service)




add_subdirectory(protocal)
add_subdirectory(server)
add_subdirectory(service)
add_subdirectory(hotel)


#add_library(protocal_lib protocal/protocal.cpp)
#add_library(server_lib server/server.cpp)
#add_library(service_lib service/service.cpp)
#add_library(hotel_lib hotel/hotel.cpp)

add_executable(myhotel main.cpp)

#target_link_libraries(${PROJECT_NAME} PRIVATE server_lib protocal_lib service_lib hotel_lib)

target_link_libraries(myhotel PRIVATE server_lib)









