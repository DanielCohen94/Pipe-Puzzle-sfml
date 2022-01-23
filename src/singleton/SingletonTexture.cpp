#include "SingletonTexture.h"
#include <exception>

//===================private constructor======================
SingletonTexture::SingletonTexture()
{
	if (!m_background.loadFromFile("background_pipes.png"))
		throw std::exception("cant open background_pipes");

	if (!m_pipe_end.loadFromFile("end.png"))
		throw std::exception("cant open pipe_end");

	if (!m_pipe_start.loadFromFile("start.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_corner_empty.loadFromFile("corner_empty.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_corner_full.loadFromFile("corner_full.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_vertical_empty.loadFromFile("vertical_empty.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_vertical_full.loadFromFile("vertical_full.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_triple_empty.loadFromFile("triple_empty.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_triple_full.loadFromFile("triple_full.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_quadruple_empty.loadFromFile("quadruple_empty.png"))
		throw std::exception("cant open pipe_start");

	if (!m_pipe_quadruple_full.loadFromFile("quadruple_full.png"))
		throw std::exception("cant open pipe_start");

	if (!m_background_menu.loadFromFile("back_menu.png"))
		throw std::exception("cant open back_menu");

	if (!m_loading.loadFromFile("loading.png"))
		throw std::exception("cant open num1");

}
//=============================================================
SingletonTexture& SingletonTexture::instance()
{
	static SingletonTexture inst;
	return inst;
}

//========================= get section =======================
const sf::Texture& SingletonTexture::getBackgroundTexture() const
{
	return m_background;
}
//=============================================================
const sf::Texture& SingletonTexture::getLoadingTexture() const
{
	return m_loading;
}
//=============================================================
const sf::Texture& SingletonTexture::getmPipeEndTexture() const
{
	return m_pipe_end;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeStartTexture() const
{
	return m_pipe_start;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeCornerEmptyTexture() const
{
	return m_pipe_corner_empty;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeCornerFullTexture() const
{
	return m_pipe_corner_full;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeVerticalEmptyTexture() const
{
	return m_pipe_vertical_empty;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeVerticalfullTexture() const
{
	return m_pipe_vertical_full;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeTripleEmptyTexture() const
{
	return m_pipe_triple_empty;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeTriplefullTexture() const
{
	return m_pipe_triple_full;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeQuadrupleEmptyTexture() const
{
	return m_pipe_quadruple_empty;
}
//=============================================================
const sf::Texture& SingletonTexture::getPipeQuadruplefullTexture() const
{
	return m_pipe_quadruple_full;
}
//=============================================================
const sf::Texture& SingletonTexture::getBackgroundMenu() const
{
	return m_background_menu;
}
//=============================================================
