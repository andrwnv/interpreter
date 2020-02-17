cmake_minimum_required(VERSION 3.0)

project(simple_compiler)

set (CMAKE_INCLUDE_CURRENT_DIR ON) # Find includes in corresponding build directories
set (CMAKE_AUTOMOC ON) # Instruct CMake to run moc automatically when needed

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

include_directories(src)

set (PROJECT_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp ${HEADERS_INCLUDE} ${SOURCES_INCLUDE}
        # src/...
)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)