cmake_minimum_required(VERSION 3.7)

project(SnakeGame)

set( SOURCE_FILES src/SnakeGameMain.c src/Defines.h src/SnakeMenu.c src/SnakeMenu.h src/SnakeScore.c src/SnakeScore.h src/Snake.c src/Snake.h src/SnakeCursor.c src/SnakeCursor.h src/SnakeMap.c src/SnakeMap.h)

add_executable(SnakeGame ${SOURCE_FILES})
