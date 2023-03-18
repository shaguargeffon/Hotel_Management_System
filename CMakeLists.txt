cmake_minimum_required(VERSION 3.0)

project(HOTEL)

#target_compile_features(myhotel PUBLIC cxx_std_17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_CXX_STANDARD 17 CACHE STRING "the C++ standard to use for this project")

#string(REGEX REPLACE "(.*)/" "\\1" PROJECT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

#message("The directory is: " ${CMAKE_CURRENT_SOURCE_DIR})

#include_directories(${PROJECT_PATH}/server)


#include_directories(${PROJECT_SOURCE_DIR}/hotel)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/service)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/types)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/com)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/handler)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/database)

add_subdirectory(database)
add_subdirectory(handler)
add_subdirectory(com)



#add_library(protocal_lib protocal/protocal.cpp)
#add_library(server_lib server/server.cpp)
#add_library(service_lib service/service.cpp)
#add_library(hotel_lib hotel/hotel.cpp)

add_executable(myhotel main.cpp)
#target_compile_features(myhotel PUBLIC cxx_std_17)

#target_link_libraries(${PROJECT_NAME} PRIVATE server_lib protocal_lib service_lib hotel_lib)


target_link_libraries(myhotel PRIVATE database_lib com_lib handler_lib)









