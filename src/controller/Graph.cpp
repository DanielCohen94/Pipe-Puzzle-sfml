#include "Graph.h"

//============================== public functions =============================

/*
	FillWaterDFS: Puts all the source in queue.
		then goes through the queue and asks everyone who is connected to
		him in the list of neighbors.
		He puts the connected in queue as well.
		Sets aside, 
		anyone who has been in line since the beginning of the algorithm's run
		and returns it at the end.
*/
//=============================================================================
const std::set<int> Graph::FillWaterDFS()
{
	std::queue<int> queuePipes;
	std::set<int> toTurnOn;
	for (auto& obj : m_sources) {
		toTurnOn.insert(obj);
		queuePipes.push(obj);
	}
	while (!queuePipes.empty())
	{
		auto it = m_List_neighbors.find(queuePipes.front());
		queuePipes.pop();
		for (auto itlist = it->second.cbegin(); itlist != it->second.cend();itlist++)
		{
			if (isConnected(it->first, *itlist)
				&& toTurnOn.find(itlist->second) == toTurnOn.cend())
			{
				queuePipes.push(itlist->second);
				toTurnOn.insert(itlist->second);
			}
		}
	}
	updateFinish(toTurnOn);
	return toTurnOn;
}

//=============================================================================
void Graph::rotate(const size_t sn, const int mouse)
{
	if(sn < m_pipes.size())
	(mouse)?
		m_pipes[sn]->turnAroundLeft() :
		m_pipes[sn]->turnAroundRight();
}
//=============================================================================
void Graph::preparationNewLlevel()
{
	m_List_neighbors.clear();
	m_sources.clear();
	m_pipes.clear();
	m_targets.clear();
	m_is_finish = false;
}

//=============================================================================
void Graph::makeNeighborhoodsMat(const std::vector<std::vector<int>>& grid)
{
	for (size_t i = 0; i < grid.size();i++)
		for (size_t j = 0; j < grid[i].size();j++)
			if (grid[i][j]!=-1)
				m_List_neighbors.insert(std::pair(grid[i][j], getNeighbors(grid, i, j)));
}

//============================ private functions ==============================
/*
	Auxiliary function for building the list of neighbors.
	to each vertex, returns a list of pairs
	(vertex and its direction in relation to the vertex sent)
*/
std::list< std::pair< Action, int> >
	Graph::getNeighbors(const std::vector<std::vector<int>>& grid,const size_t i ,const size_t j)
{
	std::list< std::pair< Action, int> > li;
	if (i > 0)
		if (grid[i - 1][j] != -1)
			li.push_back(std::pair(Action::Up, grid[i - 1][j]));

	if (j < grid[i].size() - 1)
		if (grid[i][j + 1] != -1)
			li.push_back(std::pair(Action::Right, grid[i][j + 1]));

	if (i != grid.size() - 1)
		if (grid[i + 1][j] != -1)
			li.push_back(std::pair(Action::Down, grid[i + 1][j]));

	if (j > 0)
		if (grid[i][j - 1] != -1)
			li.push_back(std::pair(Action::Left, grid[i][j - 1]));

	return li;
}

// Auxiliary function for dfs
//=============================================================================
bool Graph::isConnected(const int sn,const std::pair<Action, int> b)
{
	return m_pipes[sn]->IsConnectionNeighbor(*m_pipes[b.second].get(), b.first);
}

//=============================================================================
void Graph::updateFinish(const std::set<int> lit_on)
{
	bool finish = true;
	for (auto& tar : m_targets)
		if (lit_on.find(tar) == lit_on.cend())
			finish = false;
	m_is_finish = finish;
}