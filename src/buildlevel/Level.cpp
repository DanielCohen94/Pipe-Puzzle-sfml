#include "Level.h"
#include "Macros.h"
#include "Utilities.h"

// ============================ Constructor ===============================
Level::Level(const size_t routes) : m_num_route((routes % size_t(Numbers::Three)) + 1)
{
	while (!fillRoute());
    fillGrid();
}

//============================= private functions =========================

/*
	fillRoute : Builds a route in a random way.
		Can cause faults (deviation from an array 
		or change of value that has already entered),
		so when there is a fault we will return that the route was not built,
		and this will happen in a loop until a normal route comes out.
*/
//=========================================================================
const bool Level::fillRoute()
{
	clear();
	for (size_t i = 0; i < m_route.size();i++) {
		if (i == 0) {
			m_route[i].push_back(point(getRandom(SIZE_GAME_X), getRandom(SIZE_GAME_Y)));
			m_grid[m_route[i].back().first][m_route[i].back().second] = -1;
		}
		else
		{
			auto index = getRandom((unsigned int)(m_route[i - size_t(1)].size() - size_t(1))) + 1;
			m_route[i].push_back(point(m_route[i - 1][index].first, m_route[i - 1][index].second));
			m_grid[m_route[i - 1][index].first][m_route[i - 1][index].second] = -2;
		}
		for (size_t j = 0; j < (ROUTE_LENGTH - m_num_route); j++)
		{
			auto direction = getRandom(int(Numbers::Four));
			switch (direction)
			{
				case int(Numbers::Zero) ://right
					if (SIZE_GAME_Y - 1 == m_route[i].back().second)
						return false;
					if (m_grid[m_route[i].back().first][m_route[i].back().second + 1] != 0)
						return false;
					m_grid[m_route[i].back().first][m_route[i].back().second + 1] = -1;
					m_route[i].push_back(point(m_route[i].back().first,
						m_route[i].back().second + 1));
					break;

				case int(Numbers::One) ://up
					if (m_route[i].back().first == 0)
						return false;
					if (m_grid[m_route[i].back().first - 1][m_route[i].back().second] != 0)
						return false;
					m_grid[m_route[i].back().first - 1][m_route[i].back().second] = -1;
					m_route[i].push_back(point(m_route[i].back().first - 1,
						m_route[i].back().second));
					break;

				case int(Numbers::Two) ://left
					if (m_route[i].back().second == 0)
						return false;
					if (m_grid[m_route[i].back().first][m_route[i].back().second - 1] != 0)
						return false;
					m_grid[m_route[i].back().first][m_route[i].back().second - 1] = -1;
					m_route[i].push_back(point(m_route[i].back().first,
						m_route[i].back().second - 1));
					break;

				case int(Numbers::Three) ://down
					if (m_grid.size() - 1 == m_route[i].back().first)
						return false;
					if (m_grid[m_route[i].back().first + 1][m_route[i].back().second] != 0)
						return false;
					m_grid[m_route[i].back().first + 1][m_route[i].back().second] = -1;
					m_route[i].push_back(point(m_route[i].back().first + size_t(1),
						m_route[i].back().second));
					break;

				default:
					break;
			}
		}
	}
	return true;
}

/*
	fillGrid : Once a proper trajectory has been obtained,
		go over it and place objects so that the
		trajectory obtained can be "solvable" on the board.
		At the end, enterd randomly data to the other empty spaces
*/
//=========================================================================
void Level::fillGrid()
{
	for (size_t i = 0; i < m_route.size();i++)
		for (size_t j = 0; j < m_route[i].size();j++)
		{
			if (i == 0 && j == 0)
				m_grid[m_route[i][j].first][m_route[i][j].second] = (int)PipeType::StartPipe;
			else {
				if (j == m_route[i].size() - 1)
				{
					m_grid[m_route[i][j].first][m_route[i][j].second] = (int)PipeType::EndPipe;
					if (m_route[i][j - 1].first == m_route[i][j].first 
						&& m_route[i][j - 1].second < m_route[i][j].second)
					{
						m_dir_end_data[i].first = int(Action::Left);
						m_dir_end_data[i].second = m_route[i][j];
					}
					else if (m_route[i][j - 1].first == m_route[i][j].first 
						&& m_route[i][j - 1].second > m_route[i][j].second)
					{
						m_dir_end_data[i].first = int(Action::Right);
						m_dir_end_data[i].second = m_route[i][j];
					}
					else if (m_route[i][j - 1].second == m_route[i][j].second 
						&& m_route[i][j - 1].first > m_route[i][j].first)
					{
						m_dir_end_data[i].first = int(Action::Down);
						m_dir_end_data[i].second = m_route[i][j];

					}
					else if (m_route[i][j - 1].second == m_route[i][j].second 
						&& m_route[i][j - 1].first < m_route[i][j].first)
					{
						m_dir_end_data[i].first = int(Action::Up);
						m_dir_end_data[i].second = m_route[i][j];
					}
				}
				else {
					if (j == 0)
						m_grid[m_route[i][j].first][m_route[i][j].second] = (int)PipeType::QuadruplePipe;
					else {
						if (((m_route[i][j - 1].first == m_route[i][j].first) 
							&& (m_route[i][j].first == m_route[i][j + 1].first)) ||
							((m_route[i][j - 1].second == m_route[i][j].second) 
								&& (m_route[i][j].second == m_route[i][j + 1].second)))
							m_grid[m_route[i][j].first][m_route[i][j].second] = (int)PipeType::VerticalPipe;
						else
							m_grid[m_route[i][j].first][m_route[i][j].second] = (int)PipeType::CornerPipe;
					}
				}
			}
		}
	fillGridEmptyCells();
	sortEndPipe();

}
//=========================================================================
void Level::clear()
{
	m_grid.clear();
	m_route.clear();
	m_route.resize(m_num_route);
	m_dir_end_data.resize(m_num_route);
	m_dir_end_index.resize(3);
	m_grid.resize(SIZE_GAME_X);
	for (auto& row : m_grid)
	{
		row.resize(SIZE_GAME_Y);
		for (auto& cell : row)
			cell = 0;
	}
}
//=========================================================================
const int Level::getRandom(unsigned int modulo) const
{
	return rand() % modulo;
}
//=========================================================================
void Level::fillGridEmptyCells()
{
	for (auto& x : m_grid)
		for (auto& y : x)
			if (y == 0)
				y = getRandom(int(Numbers::Five));
}

//=========================================================================
void Level::sortEndPipe()
{
	std::sort(m_dir_end_data.begin(), m_dir_end_data.end(), comp);
	for (size_t i = 0; i < m_dir_end_data.size();i++)
	{
		m_dir_end_index[i] = m_dir_end_data[i].first;
	}
}

