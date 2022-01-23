#pragma once
#include "Graph.h"
#include "Board.h"
#include "ContainerStatus.h"

/*
	Controller : Responsible for the link between the graph and the board.
		And printing the board with the data of the current level
*/
class Controller {

public:
	
	// Constructor /Distructor
	Controller();
	~Controller() = default;
	
	// public functions
	void newGame(const std::vector<std::vector<int>>&, const std::vector<int>&);
	const bool handleClicks(const sf::Vector2f , const int );
	void render(sf::RenderWindow& window,const size_t m_levelnum,const bool = false);
	void clearGame();

private:

	// private members
	Graph m_graph;
	Board m_board;
	ContainerStatus m_cont_status;
	size_t m_clicks;
	sf::Sprite m_background;

	// private functions
	void UpdateConnectedPipes();

	void MixingDirections();

}; //end Controller