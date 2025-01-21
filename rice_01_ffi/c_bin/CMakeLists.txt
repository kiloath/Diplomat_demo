cmake_minimum_required(VERSION 3.15)
project(rice01 CXX)




add_library(rice01 src/rice01.cpp)
target_include_directories(rice01 PUBLIC include)



set_target_properties(rice01 PROPERTIES PUBLIC_HEADER "include/rice01.h")
install(TARGETS rice01)
