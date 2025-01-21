cmake_minimum_required(VERSION 3.15)
project(rice02 C)

add_executable(rice02 src/main.c)

target_link_directories(${PROJECT_NAME} PRIVATE ${LIBS_DIR})
list(APPEND EXTRA_LIBS ${LIBS})
# target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})
target_link_libraries(${PROJECT_NAME} "../../c/build/Release/diplomat_example")