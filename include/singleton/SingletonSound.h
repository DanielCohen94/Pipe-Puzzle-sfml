#pragma once
#include <SFML/Audio.hpp>

class SingletonSound
{
public:

	~SingletonSound() = default;
	//===================public function=================
	const sf::SoundBuffer& getBackgroundSound() const;
	const sf::SoundBuffer& getPipeEndSound() const;
	const sf::SoundBuffer& getWinSound() const;
	//===================public static=================
	static SingletonSound& instance();

private:

	//=========private constructor======================
	SingletonSound();
	//=========private members======================
	sf::SoundBuffer m_background;
	sf::SoundBuffer m_pipe_end_press;
	sf::SoundBuffer m_win;

}; // end SingletonSound