cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

project(eroder)

set(EXECUTABLE_OUTPUT_PATH "release")

find_package(SDL2 REQUIRED)

find_package(OpenGL REQUIRED COMPONENTS OpenGL)

find_package(GLEW REQUIRED)
include_directories(GLEW::GLEW)

find_package(OpenMP REQUIRED)

include_directories("src/extern")

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/src/*.h"
	"${PROJECT_SOURCE_DIR}/src/extern/imgui/*.cpp"
	"${PROJECT_SOURCE_DIR}/src/extern/imgui/*.h"
)

add_executable(${PROJECT_NAME} ${all_SRCS})

target_link_libraries(${PROJECT_NAME} OpenMP::OpenMP_CXX)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2 SDL2::SDL2main)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)
target_link_libraries(${PROJECT_NAME} OpenGL::OpenGL)
