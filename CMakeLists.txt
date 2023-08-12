cmake_minimum_required(VERSION 3.0)

project(HOTEL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/types)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/database)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/execution_manager)
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MessageHandler)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/EventHandler)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/com)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/protocol)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/frame)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/FrameHandler)


### add_library needs to be added in each file which uses the library.
add_library(frame_handler_lib FrameHandler/frame_handler.cpp)
add_library(frame_lib frame/frame.cpp)
add_library(com_lib com/com.cpp)
add_library(protocol_lib protocol/protocol.cpp)
add_library(event_handler_lib EventHandler/event_handler.cpp)


add_executable(myhotel main.cpp)


#target_compile_features(myhotel PUBLIC cxx_std_17)

#target_link_libraries(myhotel PRIVATE execution_manager database_lib com_lib service_lib)

#target_link_libraries(myhotel PRIVATE com_lib frame_handler_lib frame_lib)

target_link_libraries(myhotel PRIVATE protocol_lib com_lib frame_handler_lib frame_lib event_handler_lib)


