cmake_minimum_required(VERSION 3.0)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)


project(HOTEL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/EventHandler)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/com)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/frame)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sqlite)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/database)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/service)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/service_manager)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/request_handler)



### add_library needs to be added in each file which uses the library.
#add_library(frame_lib frame/frame.cpp)
add_library(com_lib com/com.cpp)
add_library(service_manager_lib service_manager/service_manager.cpp)
add_library(service_lib service/service.cpp)
#add_library(sqlite_lib sqlite/sqlite3.c)
#add_library(database_lib database/database.cpp)
#include_directories(${PROJECT_PATH}/database/thirdparty/SQLiteCpp)
#add_library(request_handler_lib request_handler/request_handler.cpp)


add_executable(myhotel main.cpp)

#find_package(sqlite3)


#target_compile_features(myhotel PUBLIC cxx_std_17)

#target_link_libraries(myhotel PRIVATE execution_manager database_lib com_lib service_lib)

#target_link_libraries(myhotel PRIVATE com_lib frame_handler_lib frame_lib)

target_link_libraries(myhotel PRIVATE com_lib service_manager_lib service_lib   ${CMAKE_THREAD_LIBS_INIT})

#add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/thirdparty/SQLiteCpp)

add_subdirectory(database)

