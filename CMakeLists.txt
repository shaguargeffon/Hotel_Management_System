cmake_minimum_required(VERSION 3.0)

project(HOTEL)

#include_directories(hotel)
#include_directories(protocal)
#include_directories(server)
#include_directories(service)


add_subdirectory(protocal)
add_subdirectory(server)
add_subdirectory(service)
add_subdirectory(hotel)
add_subdirectory(src)



#add_library(protocal_lib protocal/protocal.cpp)
#add_library(server_lib server/server.cpp)
#add_library(service_lib service/service.cpp)
#add_library(hotel_lib hotel/hotel.cpp)

#add_executable(${PROJECT_NAME} main.cpp)

#target_link_libraries(${PROJECT_NAME} PRIVATE server_lib protocal_lib service_lib hotel_lib)











