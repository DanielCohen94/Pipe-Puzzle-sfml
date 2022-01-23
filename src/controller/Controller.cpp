#include "Controller.h"
#include "SingletonTexture.h"
#include<windows.h>

//========================== Constructor ======================================
Controller::Controller() :m_clicks(0), m_board(), m_graph(), m_cont_status()
{
	m_background.setTexture(SingletonTexture::instance().getBackgroundTexture());
}

//========================== public functions =================================

// newGame : get mat, and add data to garph and board according to the mat
//=============================================================================
void Controller::newGame
	(const std::vector<std::vector<int>>& mat, const std::vector<int>& d_end)
{
	int sn = 0;
	size_t index_d_end = 0;
	// A matrix that holds the numbers of existing objects.
	// A list of neighbors was built from it at the end
	std::vector<std::vector<int>> grid;
	grid.resize(mat.size());
	for (size_t i = 0; i < mat.size();i++)
	{
		grid[i].resize(mat[i].size());
		for (size_t j = 0; j < mat[i].size();j++)
		{
			switch (mat[i][j])
			{
			case (int)PipeType::CornerPipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getPipeCornerFullTexture(),
					SingletonTexture::instance().getPipeCornerEmptyTexture());
				m_graph.addPipeData<CornerPipe>();
				grid[i][j] = sn++;
				break;

			case (int)PipeType::VerticalPipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getPipeVerticalfullTexture(),
					SingletonTexture::instance().getPipeVerticalEmptyTexture());
				m_graph.addPipeData<VerticalPipe>();
				grid[i][j] = sn++;
				break;

			case (int)PipeType::TriplePipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getPipeTriplefullTexture(),
					SingletonTexture::instance().getPipeTripleEmptyTexture());
				m_graph.addPipeData<TriplePipe>();
				grid[i][j] = sn++;
				break;

			case (int)PipeType::QuadruplePipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getPipeQuadruplefullTexture(),
					SingletonTexture::instance().getPipeQuadrupleEmptyTexture());
				m_graph.addPipeData<QuadruplePipe>();
				grid[i][j] = sn++;
				break;

			case (int)PipeType::StartPipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getPipeStartTexture());
				m_graph.addPipeData<StartPipe>();
				m_graph.addSource(sn);
				grid[i][j] = sn++;
				break;

			case (int)PipeType::EndPipe:
				m_board.addPipe(
					sf::Vector2f(float(j), float(i)),
					SingletonTexture::instance().getmPipeEndTexture(), false);
				m_board.rotateLast(d_end[index_d_end]);
				m_graph.addPipeEnd(d_end[index_d_end]);
				m_graph.addTarget(sn);
				grid[i][j] = sn++;
				index_d_end++;
				break;

			default:
				grid[i][j] = -1;
				break;
			}
		}
	}
	m_graph.makeNeighborhoodsMat(grid);
	MixingDirections();
	UpdateConnectedPipes();
}

// handleClicks : Sends to a board that will rotate in sfml objects.
//		If rotated, also executes on the graph 
//		and runs an algorithm to fill pipes that connected to the source
//=============================================================================
const bool Controller::handleClicks(const sf::Vector2f posm,const int mouse_l_or_r)
{
	auto turn = 0;
	auto finish = false;
	turn = m_board.getIndex(posm);
	if (turn != -1) {
		m_board.rotate(turn, mouse_l_or_r);
		m_graph.rotate(turn, mouse_l_or_r);
		UpdateConnectedPipes();
		m_clicks++;
		finish = m_graph.isFinish();
	}
	return !finish;
}

//=============================================================================
void Controller::render(sf::RenderWindow& window, const size_t m_levelnum,const bool pass)
{
	window.clear();

	window.draw(m_background);
	
	m_board.render(window);
	(pass)?
		m_cont_status.renderWin(window, m_clicks, m_levelnum):
		m_cont_status.render(window, m_clicks, m_levelnum);

	window.display();
	if(pass)
		Sleep(3000);
}

//=============================================================================
void Controller::clearGame()
{
	m_graph.preparationNewLlevel();
	m_board.preparationNewLlevel();
	m_clicks = 0;
}

//=============================================================================
void Controller::UpdateConnectedPipes()
{
	auto b = m_graph.FillWaterDFS();
	m_board.fillPipe(b);
}

//=============================================================================
void Controller::MixingDirections()
{
	for (size_t i = 0; i < MAX_OBJ;i++)
	{
		auto mix = std::rand() % 2;
		if(m_board.rotate(i,mix))
			m_graph.rotate(i, mix);
	}
}
