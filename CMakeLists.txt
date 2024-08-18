cmake_minimum_required(VERSION 3.20)

project(TicTacToe)

set (linkLibs SDL2main SDL2 SDL2_image SDL2_ttf)

if(WIN32)
    set (linkLibs mingw32 ${linkLibs})
    link_directories(vendor/SDL2/lib)
endif()


add_executable(TicTacToe source/main.cpp)
target_include_directories(TicTacToe PUBLIC vendor/SDL2/include source/include)
target_link_libraries(TicTacToe PUBLIC ${linkLibs})
