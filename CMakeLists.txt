cmake_minimum_required(VERSION 3.10)
project(badword)
set (CMAKE_CXX_STANDARD 17)

set(SOURCE main.cpp Window.cpp StartMenu.cpp GameScene.cpp BadWordRandomizer.cpp Grid.cpp)
set(ASSETS_HEADERS font.h sounds/sound1.h sounds/sound2.h sounds/sound3.h sounds/sound4.h random.hpp Grid.h)
set(HEADERS Window.h BaseScene.h StartMenu.h Timer.h GameScene.h Vector2.h BadWordRandomizer.h ${ASSETS_HEADERS})

add_link_options(-lraylib -lGL -lm -lpthread -ldl -lrt -lX11)
add_executable(badword ${SOURCE} ${HEADERS}) 
