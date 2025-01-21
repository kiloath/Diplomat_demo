cmake_minimum_required(VERSION 3.15)
project(diplomat_example C)
add_definitions(-DDIPLOMAT_EXAMPLE_EXPORT=1)
add_library(${PROJECT_NAME} main.c lib.c)

target_link_directories(${PROJECT_NAME} PRIVATE ${LIBS_DIR})
list(APPEND EXTRA_LIBS ${LIBS})
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
