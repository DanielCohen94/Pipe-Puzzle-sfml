#include "SingletonFont.h"
#include <exception>

//=========private constructor======================
SingletonFont::SingletonFont()
{
	if (!m_font_game.loadFromFile("fontgame.ttf"))
		throw std::exception("cant open font_game.ttf");
}
//==============================================================
SingletonFont& SingletonFont::instance()
{
	static SingletonFont inst;
	return inst;
}
//========================= get section  =======================
const sf::Font& SingletonFont::getGameFont() const
{
	return m_font_game;
}


