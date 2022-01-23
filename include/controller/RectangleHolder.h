#pragma once

#include <SFML/Graphics.hpp>

/*
	RectangleHolder : 
	Holds a rectangle drawn in the game. 
	And the accompanying data in order to draw it correctly
*/
class RectangleHolder {

public:
	// Constructor : get two RectangleShape
	RectangleHolder
	(const bool x, const bool y, const  sf::RectangleShape s, const sf::RectangleShape s2) :
		m_can_rotate(x), m_is_on(y), m_spr_on(s), m_spr_off(s2) {};
	
	// Constructor : get one RectangleShape
	RectangleHolder(const bool x, const bool y, const sf::RectangleShape s) :
		m_can_rotate(x), m_is_on(y), m_spr_on(s), m_spr_off(){};

	// Distructor
	~RectangleHolder() = default;

	// public functions
	const sf::RectangleShape& getSprite()const;
	void rotate(const int);
	const bool getIsOn()const { return m_is_on; };
	const bool getCanRotate()const { return m_can_rotate; };
	void setOn() { m_is_on = true; };
	void setOff() { m_is_on = false; };

private:
	//private members
	bool m_can_rotate;
	bool m_is_on;
	sf::RectangleShape m_spr_off;
	sf::RectangleShape m_spr_on;

}; // end RectangleHolder