#include "SingletonSound.h"
#include <exception>

//===================private constructor======================
SingletonSound::SingletonSound()
{
	if (!m_background.loadFromFile("background_sound.wav"))
		throw std::exception("cant open background_sound");
	
	if (!m_pipe_end_press.loadFromFile("pipe_end_press.wav"))
		throw std::exception("cant open m_pipe_end_press");
	
	if (!m_win.loadFromFile("win_s.wav"))
		throw std::exception("cant open m_pipe_end_press");
}
//=============================================================
SingletonSound& SingletonSound::instance() {

	static  SingletonSound inst;
	return inst;
}

//========================= get section =======================
const sf::SoundBuffer& SingletonSound::getBackgroundSound() const
{
	return m_background;
}
//=============================================================
const sf::SoundBuffer& SingletonSound::getPipeEndSound() const
{
	return m_pipe_end_press;
}
//=============================================================
const sf::SoundBuffer& SingletonSound::getWinSound() const
{
	return m_win;
}