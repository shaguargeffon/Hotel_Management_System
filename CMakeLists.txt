cmake_minimum_required(VERSION 3.0)

project(hotel)


add_library(server_lib server/server.cpp)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE server_lib)











