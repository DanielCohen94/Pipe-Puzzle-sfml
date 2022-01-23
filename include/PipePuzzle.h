#pragma once

#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Menu.h"
#include "Controller.h"

/*
	PipePuzzle:
	The main object in the game. 
	Runs in a loop as long as the sfml window is open
*/
class PipePuzzle
{
public:
	// public functions
	PipePuzzle();
	~PipePuzzle() = default;
	void run();

private:
	// using section
	using Levels = std::vector< Level>;

	//private members
	sf::RenderWindow m_window;
	sf::Sprite m_loading;
	Controller m_Controller;
	Menu m_menu;
	Levels m_levels;
	bool m_in_level;
	size_t m_levelnum;
	
	//private functions
	void runMenu();
	void handleMouseButtonPressed(const sf::Event&);
	void resetlevel();

}; // end PipePuzzle