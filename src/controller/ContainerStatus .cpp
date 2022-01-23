#include "ContainerStatus.h"
#include "SingletonFont.h"
#include "Macros.h"

//=========================== Constructor =====================================
ContainerStatus::ContainerStatus() {
	
	initText(m_level, LEVEL_T_POS, sf::Color::Red, sf::Color::White, "Level: ");
	initText(m_number_level, LEVEL_N_POS, sf::Color::Red, sf::Color::White);
	initText(m_clicks, CLICKS_T_POS, sf::Color::Red, sf::Color::White, "Clicks: ");
	initText(m_number_clicks, CLICKS_N_POS, sf::Color::Red, sf::Color::White);
	initText(m_win, WIN_T_POS, sf::Color::Green, sf::Color::White, "You Win !");
}

//=========================== public functins =================================
void ContainerStatus::render(sf::RenderWindow& window, size_t clicks, size_t levelnum)
{
	m_number_clicks.setString(std::to_string(clicks));
	m_number_level.setString(std::to_string(levelnum + 1));
	
	window.draw(m_number_clicks);
	window.draw(m_number_level);
	window.draw(m_clicks);
	window.draw(m_level);
}
//=============================================================================
void ContainerStatus::renderWin(sf::RenderWindow& window, size_t clicks, size_t levelnum)
{
	window.draw(m_win);
	this->render(window, clicks, levelnum);
}
//============================== private functions =============================
void ContainerStatus::initText
(sf::Text& text, const sf::Vector2f pos, const sf::Color fill, const sf::Color out, std::string str)
{
	text.setFont(SingletonFont::instance().getGameFont());
	text.setPosition(pos);
	text.setFillColor(fill);
	text.setCharacterSize(CHARACTER_SIZE);
	text.setStyle(sf::Text::Bold);
	text.setOutlineColor(out);
	text.setOutlineThickness(OUTLINE_THCKNESS);
	text.setString(str);
}
