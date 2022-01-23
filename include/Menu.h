#pragma once

#include <algorithm>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Menu {

public:
	// public functions
	Menu();
	void setOnLevel(const size_t);
	const int getLevelNum(sf::RenderWindow&);
	void render(sf::RenderWindow& window);

private:
	typedef std::pair< sf::RectangleShape, bool> pair;
	using MenuData = std::vector< pair >;
	
	// private members
	std::vector< sf::Text > m_numbers;
	MenuData m_data;
	bool m_winner;
	sf::Sprite m_background;
	sf::Sound m_background_sound;
	sf::Sound m_winner_sound;
	sf::Text m_winner_t;

}; // end Menu