cmake_minimum_required(VERSION 3.0.0)
project(iz1)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -Wpedantic -Wextra -Werror")

add_subdirectory(calculate_side_length)

message("CALCULATOR_LIB_INCLUDE_DIRS = ${CALCULATOR_LIB_INCLUDE_DIRS}")
message("CALCULATOR_LIB_LIBRARIES = ${CALCULATOR_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.c)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )

target_include_directories(${PROJECT_NAME} PUBLIC ${CALCULATOR_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CALCULATOR_LIB_LIBRARIES})
target_link_libraries(${PROJECT_NAME} PRIVATE m)

add_subdirectory(tests)