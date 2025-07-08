cmake_minimum_required(VERSION 3.10.0)
project(image-displayer VERSION 1.0 LANGUAGES C)

include_directories(tools includes src bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SOURCE_DIR/bin})

add_executable(image-displayer src/main.c tools/reader.c)