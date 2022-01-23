#include "PipePuzzle.h"
#include "Macros.h"
#include "SingletonTexture.h"

//============================ Constructor =============================
PipePuzzle::PipePuzzle() :
	m_window(sf::VideoMode(WINSOW_SIZE_X, WINSOW_SIZE_Y), "Pipe puzzle"),
	m_in_level(false),
	m_menu(),
	m_Controller(),
	m_levelnum(0)
{
	std::srand((unsigned int)std::time(NULL));
	m_loading.setTexture(SingletonTexture::instance().getLoadingTexture());

	m_window.setKeyRepeatEnabled(false);
	m_window.setVerticalSyncEnabled(true);
	m_window.setFramerateLimit(FRAMERATE_LIMIT);

	m_window.clear();
	m_window.draw(m_loading);
	m_window.display();

	for (size_t i{ 0 }; i < NUM_LEVELES; i++)
		m_levels.push_back(Level(i));
}

//=========================== public functions =========================
void PipePuzzle::run()
{
	while (m_window.isOpen())
	{
		if (!m_in_level)
			runMenu();
		if (auto event = sf::Event{}; m_window.waitEvent(event))
		{
			m_Controller.render(m_window, m_levelnum);
			
			switch (event.type)
			{
				case sf::Event::Closed:
					m_window.close();
					break;

				case sf::Event::KeyPressed:
					if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
					break;

				case sf::Event::MouseButtonPressed:
					handleMouseButtonPressed(event);
					break;
			}
		}
	}
}

//=========================== private functions =========================

// runMenu : Receives a level number from the menu.
// Gets the grid and direction to end pipe and sends it to a controller,
// that will build a new level
//=======================================================================
void PipePuzzle::runMenu()
{
	m_menu.render(m_window);
	m_levelnum = m_menu.getLevelNum(m_window);
	if (m_levelnum != -1) {
		m_in_level = true;
		auto mat = m_levels[m_levelnum].getGrid();
		auto d_end = m_levels[m_levelnum].getDirEnd();
		m_Controller.newGame(mat, d_end);
	}
}

// Lets the controller manage the clicks for pipe puzzle.
// The controller will return if the level is complete
//=======================================================================
void PipePuzzle::handleMouseButtonPressed(const sf::Event& event)
{
	sf::Vector2f posm = m_window.mapPixelToCoords
		({ event.mouseButton.x, event.mouseButton.y });
	
	switch (event.mouseButton.button) {
		case sf::Mouse::Left:
			m_in_level = m_Controller.handleClicks(posm, 0);
			break;
		case sf::Mouse::Right:
			m_in_level = m_Controller.handleClicks(posm, 1);
			break;
	}
	if(!m_in_level)
		this->resetlevel();
}

//=======================================================================
void PipePuzzle::resetlevel()
{
	m_Controller.render(m_window, m_levelnum, true);
	m_menu.setOnLevel(m_levelnum);
	m_Controller.clearGame();
}