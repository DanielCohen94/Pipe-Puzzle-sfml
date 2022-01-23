#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class ContainerStatus {

public:
	// Constructor / Distructor
	ContainerStatus();
	~ContainerStatus() = default;
	// public functions
	void render(sf::RenderWindow&, size_t, size_t);
	void renderWin(sf::RenderWindow&, size_t, size_t);

private:
	// private members
	sf::Text m_level;
	sf::Text m_clicks;
	sf::Text m_number_level;
	sf::Text m_number_clicks;
	sf::Text m_win;

	// private functions
	void initText
		(sf::Text &,const sf::Vector2f , const sf::Color , const sf::Color ,std::string = "");

}; // end ContainerStatus