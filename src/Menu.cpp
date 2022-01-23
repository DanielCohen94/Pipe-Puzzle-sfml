#include "Menu.h"
#include "SingletonTexture.h"
#include "SingletonFont.h"
#include "SingletonSound.h"
#include "Macros.h"

//========================= constructor =============================
Menu::Menu() : m_winner(false)
{
	// Initialize all sfml variables
	// sprite
	m_background.setTexture(SingletonTexture::instance().getBackgroundMenu());
	// sound
	m_background_sound.setBuffer(SingletonSound::instance().getBackgroundSound());
	m_background_sound.setLoop(true);
	m_background_sound.setVolume(BACKGROUND_VOLUME);
	
	m_winner_sound.setBuffer(SingletonSound::instance().getWinSound());
	m_winner_sound.setLoop(true);
	m_winner_sound.setVolume(BACKGROUND_VOLUME);
	// text & rectangle
	auto y = FOUR_HUNDRED;
	for (size_t i = 0; i < NUM_LEVELES;i++)
	{
		sf::RectangleShape rectangle;
		sf::Text text;
		
		auto new_line = i % size_t(Numbers::Three);
		rectangle.setSize(SIZE_RECT);
		rectangle.setFillColor(sf::Color::Black);
		if (i && (i % size_t(Numbers::Three)) == 0)
			y += HUNDRED + FIFTY;
		rectangle.setPosition
			(TWO_HUNDRED * float(new_line) + FIVE_HUNDRED + FIFTY, y);

		text.setFont(SingletonFont::instance().getGameFont());
		text.setString(std::to_string(i + 1));
		text.setFillColor(sf::Color::Red);
		text.setCharacterSize(CHARACTER_SIZE);
		text.setStyle(sf::Text::Bold);
		text.setOutlineColor(sf::Color::White);
		text.setOutlineThickness(OUTLINE_THCKNESS);
		
		text.setPosition
			(TWO_HUNDRED * float(new_line) + FIVE_HUNDRED + SEVENTY_FIVE,y);
		
		i? rectangle.setOutlineColor(sf::Color::Red):
			rectangle.setOutlineColor(sf::Color::Green);
		rectangle.setOutlineThickness(OUTLINE_THCKNESS);

		i? m_data.push_back(pair(rectangle, false)) :
			m_data.push_back(pair(rectangle, true));

		m_numbers.push_back(text);
	}

	m_winner_t.setFont(SingletonFont::instance().getGameFont());
	m_winner_t.setPosition(WINNER_POS);
	m_winner_t.setString("champion of pipe puzzle !!!");
	m_winner_t.setFillColor(sf::Color::Red);
	m_winner_t.setCharacterSize(CHARACTER_SIZE);
	m_winner_t.setStyle(sf::Text::Bold);
	m_winner_t.setOutlineColor(sf::Color::White);
	m_winner_t.setOutlineThickness(OUTLINE_THCKNESS);

	m_background_sound.play();
}

// Turns on level
// In the next login the user will be able to enter the next level
//===================================================================
void Menu::setOnLevel(const size_t i)
{
	if (!m_winner) {
		if (i + 1 < m_data.size()) {
			m_data[i + 1].second = true;
			m_data[i + 1].first.setOutlineColor(sf::Color::Green);
		}
		if (i + 1 == m_data.size()) // If the last level is turned on
		{
			m_background_sound.stop();
			m_winner_sound.play();
			m_winner = true;
		}
	}
}

// getLevelNum : Loop until the user clicks on a valid level
// Returns the level number selected by the user
//===================================================================
const int Menu::getLevelNum(sf::RenderWindow& window) 
{
	int index = -1;
	bool getLegalLevel = false;

	while (!getLegalLevel && window.isOpen())
	if (auto event = sf::Event{}; window.waitEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				m_background_sound.stop();
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
				{
					m_background_sound.stop();
					window.close();
				}
				break;

			case sf::Event::MouseButtonPressed:
				sf::Vector2f pos = window.mapPixelToCoords
				({ event.mouseButton.x, event.mouseButton.y });

				auto i = 0;
				for (auto& rect : m_data) {
					if (rect.first.getGlobalBounds().contains(pos))
						if (rect.second) {
							index = i;
							getLegalLevel = true;
						}
					i++;
				}
				break;
		}
	}
	return index;
}

//===================================================================
void Menu::render(sf::RenderWindow& window)
{
	window.clear();

	window.draw(m_background);

	for (auto& rect : m_data)
		window.draw(rect.first);

	for (auto& num : m_numbers)
		window.draw(num);

	if (m_winner)
		window.draw(m_winner_t);

	window.display();
}