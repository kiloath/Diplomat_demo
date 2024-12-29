cmake_minimum_required(VERSION 3.15)
project(diplomat_example CXX)

add_executable(${PROJECT_NAME} tests/fixeddecimal.cpp)

target_link_directories(${PROJECT_NAME} PRIVATE ${LIBS_DIR})
list(APPEND EXTRA_LIBS ${LIBS})
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
