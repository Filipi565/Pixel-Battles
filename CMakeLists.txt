cmake_minimum_required(VERSION 3.10)
project("Pixel Battles")

include_directories("C:\\Users\\Filipi\\Documents\\C-C++ Projects\\Include" ./include)
link_directories("C:\\Users\\Filipi\\Documents\\C-C++ Projects\\Lib")

add_definitions(-mwindows -Wl,-subsystem,windows)

file(GLOB_RECURSE SOURCE "src/*.cpp")

add_library(libPixelBattle SHARED ${SOURCE})
find_library(RAYLIB raylib gdi32 winmm)

add_executable(PixelBattle src/main.cxx)

target_link_libraries(PixelBattle libPixelBattle raylib gdi32 winmm)