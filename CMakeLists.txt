cmake_minimum_required(VERSION 3.10.0)
project(image-displayer VERSION 1.0 LANGUAGES C)

find_package(PkgConfig REQUIRED)
find_package(Curses)
pkg_check_modules(SDL2 REQUIRED sdl2)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(tools includes src)

link_directories(${SDL2_LIBRARY_DIRS})

set(SOURCES 
    src/main.c 
    tools/reader.c
    tools/window.c
    tools/menu.c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_compile_options(-lncurses)

add_executable(image-displayer ${SOURCES})

target_link_libraries(image-displayer ${SDL2_LIBRARIES} ${CURSES_LIBRARIES})