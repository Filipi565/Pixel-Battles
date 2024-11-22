cmake_minimum_required(VERSION 3.10)
project("Pixel Battle")

include_directories(./include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/output)

if (DEFINED EXTRA_INCLUDE_DIRS)
    include_directories(${EXTRA_INCLUDE_DIRS})
endif(DEFINED EXTRA_INCLUDE_DIRS)

if (DEFINED EXTRA_LINK_DIRS)
    link_directories(${EXTRA_LINK_DIRS})
else() # for the find_library function
    set(EXTRA_LINK_DIRS "")
endif(DEFINED EXTRA_LINK_DIRS)

set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SOURCE "src/*.cpp")

if (WIN32)
    set(LIBRARIES gdi32 winmm)
elseif(UNIX)
    set(LIBRARIES GL m pthread dl rt X11)
elseif(APPLE)
    set(LIBRARIES "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
else()
    message(FATAL_ERROR "Platform not supported")
endif(WIN32)

find_library(RAYLIB_CWALK raylib cwalk HINTS ${EXTRA_LINK_DIRS} REQUIRED)
find_library(OTHER_LIBS ${LIBRARIES})

add_executable(PixelBattle ${SOURCE})

target_link_libraries(PixelBattle raylib cwalk ${LIBRARIES})