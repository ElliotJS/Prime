#pragma once

#define SCREEN_WIDTH sf::VideoMode::getDesktopMode().width
#define SCREEN_HEIGHT sf::VideoMode::getDesktopMode().height
#define VIEW_WIDTH 1920.0f
#define VIEW_HEIGHT 1080.0f
#define SCREEN_SCALE_X (SCREEN_WIDTH / VIEW_WIDTH)
#define SCREEN_SCALE_Y (SCREEN_HEIGHT / VIEW_HEIGHT)
#define ADJUSTED_WIDTH (SCREEN_WIDTH / SCREEN_SCALE_X)
#define ADJUSTED_HEIGHT (SCREEN_HEIGHT / SCREEN_SCALE_X)

#define CELL_SIZE 50
#define MAP_WIDTH  50
#define MAP_HEIGHT 50

#define SPLASH_SCREEN_SHOW_TIME 3.0f
#define SPLASH_SCREEN_BACKGROUND_FILEPATH "Resources/splash_screen_background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/main_menu_background.png"
#define MAIN_FONT "Resources/Charnego.ttf"

#define DEBUG_FONT "Resources/Arial.ttf"

#define PLAY_BACKGROUND_FILEPATH "Resources/main_menu_background.png"

#define PLAYER_CHARACTER_SPRITE_FILEPATH "Resources/playerChar.png"

#define CELL_BASE_SPRITE_FILEPATH "Resources/mainCell.png"
#define CELL_WALL_SPRITE_FILEPATH "Resources/wallCell.png"