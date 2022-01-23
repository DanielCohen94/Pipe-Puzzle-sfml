#pragma once
#include <SFML/graphics.hpp>

class SingletonFont
{
public:

	~SingletonFont() = default;
	//===================public function=================
	const sf::Font& getGameFont() const;
	//===================public static=================
	static SingletonFont& instance();

private:

	//=========private constructor======================
	SingletonFont();
	//=========private members======================
	sf::Font m_font_game;

};// end SingletonFont