cmake_minimum_required(VERSION 3.17)
project(tbrpg)

set(CMAKE_CXX_STANDARD 14)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES true)
find_package(SFML COMPONENTS graphics audio REQUIRED)
add_executable(tbrpg Src/main.cpp)

target_link_libraries(tbrpg sfml-graphics sfml-audio)
