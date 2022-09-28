cmake_minimum_required(VERSION 3.23)
project(excel_hello)

set(CMAKE_CXX_STANDARD 20)

link_directories(C:/Users/tosha/CLionProjects/lib/libxl-4.0.4.0/lib)

add_library(libxl C:/Users/tosha/CLionProjects/lib/libxl-4.0.4.0/lib/libxl.lib)

set_target_properties(libxl PROPERTIES LINKER_LANGUAGE CXX)

add_executable(excel_hello main.cpp base.cpp header.h funcs.cpp)

target_link_libraries(excel_hello LINK_PUBLIC libxl)

include_directories(C:/Users/tosha/CLionProjects/lib/libxl-4.0.4.0/include_cpp)
