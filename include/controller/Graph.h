#pragma once

#include <algorithm>
#include <list>
#include <unordered_map>
#include <set>
#include <queue>
#include "Pipe.h"
#include "EndPipe.h"
#include "StartPipe.h"
#include "CornerPipe.h"
#include "VerticalPipe.h"
#include "TriplePipe.h"
#include "QuadruplePipe.h"
#include "Macros.h"

/*
	Graph : Holds a list of neighbors and 
		a vector of pipes — only their information about which sides are acting on them.
		Using these two can perform dfs to find out which pipes are connected to the sources
*/
class Graph {

public:

	//Constructor/Distructor
	Graph() :m_is_finish(false) {};
	~Graph() = default;
	//public function
	const std::set<int> FillWaterDFS();
	void preparationNewLlevel();
	void rotate(const size_t sn, const int mouse);
	void makeNeighborhoodsMat(const std::vector<std::vector<int>>&);
	template <typename pipe_t>
	void addPipeData() { m_pipes.push_back(std::make_unique<pipe_t>()); };
	void addPipeEnd(const int dir) { m_pipes.push_back(std::make_unique<EndPipe>(dir)); };
	void addSource(const int sn) { m_sources.push_back(sn); };
	void addTarget(const int sn) { m_targets.push_back(sn); };
	const bool isFinish() { return m_is_finish; };
private:

	// using section
	using NeighborhoodsMat = std::unordered_map
		< int, std::list<std::pair< Action, int> >>;
	using Pipes = std::vector<std::unique_ptr<Pipe>>;
	
	//private members
	NeighborhoodsMat m_List_neighbors;
	Pipes m_pipes;
	std::list<int> m_sources;
	std::list<int> m_targets;
	bool m_is_finish;
	
	//private functions
	std::list< std::pair< Action, int> >
		getNeighbors(const std::vector<std::vector<int>>&, const size_t,const size_t);
	bool isConnected(const int sn, const std::pair<Action, int> b);
	void updateFinish(const std::set<int>);
	
};//end Graph