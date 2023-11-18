#pragma once

enum ButtonTypes { unhovered, hovered, clicked };
enum DataTypes { angle, initialSpeed, gravity, airDrag };

constexpr const double PI = 3.14159;

constexpr const int WIDTH = 1400;
constexpr const int HEIGHT = 700;

constexpr const int DEFAULT_OUTLINE = 0;

constexpr const int CANNON_POSITION_X = 5;
constexpr const int CANNON_POSITION_Y = HEIGHT - 240;
constexpr const int CANNON_SIZE_X = 65;
constexpr const int CANNON_SIZE_Y = 60;

constexpr const int BULLET_SIZE = 21;

constexpr const char* FONT = "font";
constexpr const char* FONT_PATH = "res/Roboto-Bold.ttf";
constexpr const char* FIRE_FONT = "fireFont";

constexpr const char* ICON_PATH = "res/cannon.png";

constexpr const char* CANNON = "cannon";
constexpr const char* CANNON_PATH = "res/cannon.png";

constexpr const char* BULLET = "bullet";
constexpr const char* BULLET_PATH = "res/bullet.png";