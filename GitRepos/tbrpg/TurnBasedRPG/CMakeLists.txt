cmake_minimum_required(VERSION 3.17)
project(TurnBasedRPG)

set(CMAKE_CXX_STANDARD 14)
#set(SFML_DIR Lib/SFML-2.5.1/lib/cmake/)
set(SFML_DIR SFML-2.5.1/lib/cmake/SFML)
set(SFML_STATIC_LIBRARIES true)
find_package(SFML COMPONENTS graphics audio REQUIRED)
add_executable(TurnBasedRPG Src/main.cpp)


target_link_libraries(TurnBasedRPG sfml-graphics sfml-audio)
