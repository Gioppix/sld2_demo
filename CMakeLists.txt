cmake_minimum_required(VERSION 3.9)
project(sld2_demo)

set(CMAKE_CXX_STANDARD 20)


#set(SDL2_PATH "C:\\Users\\<user_name>\\Downloads\\SDL2-2.0.7\\x86_64-w64-mingw32")

find_package(SDL2 REQUIRED)

include_directories( ${SDL2_INCLUDE_DIR} )

add_executable(sld2_demo main.cpp)

target_link_libraries(sld2_demo ${SDL2_LIBRARY} )