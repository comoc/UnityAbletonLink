cmake_minimum_required(VERSION 3.13)

project(UnityAbletonLink CXX)

add_subdirectory(link)

include_directories(link/include link/modules/asio-standalone/asio/include)

add_library(${PROJECT_NAME} SHARED MyAbletonLink.cpp Plugin.cpp)

target_link_libraries(UnityAbletonLink abl_link)