#pragma once
#include <SFML/Graphics.hpp>

const size_t NUM_LEVELES = 9;
const size_t SIZE_GAME_X = 8;
const size_t SIZE_GAME_Y = 11;
const size_t MAX_OBJ = SIZE_GAME_X * SIZE_GAME_Y;
const size_t ROUTE_LENGTH = 10;

const sf::Vector2f SIZE_RECT(100, 100);
const sf::Vector2f WINNER_POS(175, 700);
const sf::Vector2f LEVEL_T_POS(1300, 100);
const sf::Vector2f LEVEL_N_POS(1375, 200);
const sf::Vector2f CLICKS_T_POS(1300, 400);
const sf::Vector2f CLICKS_N_POS(1375, 500);
const sf::Vector2f WIN_T_POS(1200, 675);

const unsigned int FRAMERATE_LIMIT = 60;
const unsigned int CHARACTER_SIZE = 80;
const unsigned int WINSOW_SIZE_Y = 900;
const unsigned int WINSOW_SIZE_X = 1700;

const float BACKGROUND_VOLUME = 30;
const float OUTLINE_THCKNESS = 5;
const float TWO_HUNDRED = 200;
const float FIVE_HUNDRED = 500;
const float FOUR_HUNDRED = 400;
const float SEVENTY_FIVE = 75;
const float FIFTY = 50;
const float TWO_HUND_SEVENY_DEGREES = 270;
const float NINETY_DEGREES = 90;
const float HUNDRED = 100;

enum class Action
{
	Up,
	Down,
	Left,
	Right
};

enum class Numbers
{
	Zero,
	One,
	Two,
	Three,
	Four,
	Five
};

enum class PipeType
{
	EmptyPipe = 0,
	CornerPipe,
	VerticalPipe,
	QuadruplePipe,
	TriplePipe,
	StartPipe,
	EndPipe
};