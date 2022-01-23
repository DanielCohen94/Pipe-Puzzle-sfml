#pragma once

#include <vector>
#include <set>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "RectangleHolder.h"

/*
	Board: Holds all the pictures of the pipes on the board and is 
		responsible for managing them. Manages the graphic part of the game.
*/
class Board {

public:
	//Constructo/Distructor
	Board();
	~Board() = default;

	//public function
	void addPipe
	(const sf::Vector2f pos, const sf::Texture& tex, const sf::Texture& tex2);
	void addPipe
	(const sf::Vector2f pos, const sf::Texture& tex, const bool canrotate = true);
	void render(sf::RenderWindow &);
	const int getIndex(const sf::Vector2f);
	void rotateLast(const int);
	void fillPipe(const std::set<int>&);
	void preparationNewLlevel() { m_rPipes.clear(); };
	const bool rotate(const size_t, const int);

private:
	// private members
	std::vector<RectangleHolder> m_rPipes;
	sf::Sound m_s_wrong_press;

}; // end Board