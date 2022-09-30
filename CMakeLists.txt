cmake_minimum_required(VERSION 3.16.3)
project(excel_hello)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/include/libxl)

add_library(libxl SHARED IMPORTED)

set_target_properties(libxl PROPERTIES IMPORTED_LOCATION /usr/local/lib/lib64/libxl.so)

set_target_properties(libxl PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(libxl INTERFACE /usr/local/lib/lib64/)

add_executable(excel_hello main.cpp base.cpp header.h funcs.cpp)

target_link_libraries(excel_hello PUBLIC libxl)

