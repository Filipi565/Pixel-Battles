cmake_minimum_required(VERSION 3.10)
project("Pixel Battle")

include_directories("C:\\Users\\Filipi\\Documents\\C-C++ Projects\\Include" ./include)
link_directories("C:\\Users\\Filipi\\Documents\\C-C++ Projects\\Lib")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

set(CMAKE_SHARED_LIBRARY_PREFIX "")

file(GLOB_RECURSE SOURCE "src/*.cpp")

find_library(RAYLIB raylib gdi32 winmm)

add_executable(PixelBattle ${SOURCE})

target_link_libraries(PixelBattle raylib gdi32 winmm)