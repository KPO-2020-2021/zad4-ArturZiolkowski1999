cmake_minimum_required(VERSION 3.1)
project(rotation3D)

set(EXECUTABLE ${CMAKE_PROJECT_NAME}_run)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tst)
add_subdirectory(lib/googletest-master)
add_subdirectory(lib/GNUPlot)

include_directories(${CMAKE_SOURCE_DIR}/inc)
include_directories(${CMAKE_SOURCE_DIR}/lib/GNUPlot)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true inc/*.h src/*.cpp)

add_executable(${EXECUTABLE} ${SOURCES})
add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
target_link_libraries(${EXECUTABLE} PRIVATE GNUPlot_lib)
