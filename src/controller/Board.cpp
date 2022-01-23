#include "Board.h"
#include "SingletonSound.h"
#include "Macros.h"

//============================= Constructor ===================================
Board::Board()
{
	m_s_wrong_press.setBuffer(SingletonSound::instance().getPipeEndSound());
	m_s_wrong_press.setLoop(false);
	m_s_wrong_press.setVolume(100);
}
// Two functions for adding rectangles. One for those with one image and one for those with Two images
//==============================================================================
void Board::addPipe(const sf::Vector2f pos, const sf::Texture& tex, const sf::Texture& tex2)
{
	sf::RectangleShape spr1;
	spr1.setTexture(&tex);
	spr1.setSize(SIZE_RECT);
	spr1.setOrigin(SIZE_RECT / 2.f);
	spr1.setPosition(pos.x * HUNDRED + HUNDRED, pos.y * HUNDRED + HUNDRED);

	sf::RectangleShape spr2;
	spr2.setTexture(&tex2);
	spr2.setSize(SIZE_RECT);
	spr2.setOrigin(SIZE_RECT / 2.f);
	spr2.setPosition(pos.x * HUNDRED + HUNDRED, pos.y * HUNDRED + HUNDRED);

	m_rPipes.push_back(RectangleHolder(true, false, spr1, spr2));
}
//==============================================================================
void Board::addPipe(const sf::Vector2f pos, const sf::Texture& tex, const bool canrotate)
{
	sf::RectangleShape spr;
	spr.setTexture(&tex);
	spr.setSize(SIZE_RECT);
	spr.setOrigin(SIZE_RECT / 2.f);
	spr.setPosition(pos.x * HUNDRED + HUNDRED, pos.y * HUNDRED + HUNDRED);

	m_rPipes.push_back(RectangleHolder(canrotate, false, spr));
}

//==============================================================================
void Board::render(sf::RenderWindow& window)
{
	for (auto& spr : m_rPipes) 
		window.draw(spr.getSprite());
}
/*
	return index of the pipes that will rotated 
		and -1 if nobody find in that position, or end pipe was Pressed
*/
//==============================================================================
const int Board::getIndex(const sf::Vector2f pos)
{
	int sn_find = -1;
	for (size_t i = 0 ; i < m_rPipes.size();i++)
	{
		if (m_rPipes[i].getSprite().getGlobalBounds().contains(pos) && m_rPipes[i].getCanRotate())
		{
			//m_rPipes[i].rotate(mouse);
			sn_find = int(i);
			break;
		}
		else if(m_rPipes[i].getSprite().getGlobalBounds().contains(pos) && !m_rPipes[i].getCanRotate())
			m_s_wrong_press.play();
	}
	return sn_find;
}

/*
	Rotate the last one to enter in according to the direction received.
	To rotate the end vertex in its appropriate direction
*/
//==============================================================================
void Board::rotateLast(const int dir)
{
	switch (dir) {
	case int(Action::Up):
		m_rPipes[m_rPipes.size() - 1].rotate(0);
		break;
	case int(Action::Down) :
		m_rPipes[m_rPipes.size() - 1].rotate(1);
		break;
	case int(Action::Left) : 
		break;
	case int(Action::Right) :
		m_rPipes[m_rPipes.size() - 1].rotate(1);
		m_rPipes[m_rPipes.size() - 1].rotate(1);
		break;
	}
}

//==============================================================================
void Board::fillPipe(const std::set<int>& to_turn_on)
{
	for (auto& vertex : m_rPipes)
		vertex.setOff();
	
	for (const auto& turn : to_turn_on)
		m_rPipes[turn].setOn();
}

//==============================================================================
const bool Board::rotate(const size_t i , const int mouse)
{
	auto rotate = false;
	if (i < m_rPipes.size()) {
		if (m_rPipes[i].getCanRotate())
		{
			m_rPipes[i].rotate(mouse);
			rotate = true;
		}
	}
	return rotate;
}