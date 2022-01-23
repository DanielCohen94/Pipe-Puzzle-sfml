#pragma once
#include <SFML/Graphics.hpp>

class SingletonTexture
{
public:

	~SingletonTexture() = default;
	//===================public function=================
	const sf::Texture& getBackgroundTexture()const;
	const sf::Texture& getmPipeEndTexture()const;
	const sf::Texture& getPipeStartTexture()const;
	const sf::Texture& getPipeCornerEmptyTexture()const;
	const sf::Texture& getPipeCornerFullTexture()const;
	const sf::Texture& getPipeVerticalEmptyTexture()const;
	const sf::Texture& getPipeVerticalfullTexture()const;
	const sf::Texture& getPipeTripleEmptyTexture()const;
	const sf::Texture& getPipeTriplefullTexture()const;
	const sf::Texture& getPipeQuadrupleEmptyTexture()const;
	const sf::Texture& getPipeQuadruplefullTexture()const;
	const sf::Texture& getBackgroundMenu()const;
	const sf::Texture& getLoadingTexture()const;

	//===================public static=================
	static SingletonTexture& instance();

private:

	//=========private constructor======================
	SingletonTexture();
	SingletonTexture(const SingletonTexture&) = default;
	//=========private members======================
	sf::Texture m_background;
	sf::Texture m_pipe_end;
	sf::Texture m_pipe_start;
	sf::Texture m_pipe_corner_empty;
	sf::Texture m_pipe_corner_full;
	sf::Texture m_pipe_vertical_empty;
	sf::Texture m_pipe_vertical_full;
	sf::Texture m_pipe_triple_empty;
	sf::Texture m_pipe_triple_full;
	sf::Texture m_pipe_quadruple_empty;
	sf::Texture m_pipe_quadruple_full;
	sf::Texture m_background_menu;
	sf::Texture m_loading;

}; // end SingletonTexture


