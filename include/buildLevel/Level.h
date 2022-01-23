#pragma once

#include <vector>
#include <list>

using Grid = std::vector< std::vector< int > >;

/*
	Level: Builds a level.
		Returns a grid that marks the objects that will be in the level.
*/
class Level
{
public:

	// Constructor / Distructor
	Level(const size_t);
	~Level() = default;
	// public functions
	const Grid& getGrid() const { return m_grid; };
	const std::vector<int> getDirEnd() const { return m_dir_end_index; };

private:

	// using section
	typedef std::pair< size_t, size_t > point;
	typedef std::pair< int, point > dirEnd;

	using RouteMap = std::vector<std::vector<point>>;
	//private members
	Grid m_grid;
	RouteMap m_route;
	std::vector<dirEnd> m_dir_end_data;
	std::vector<int> m_dir_end_index;
	size_t m_num_route;
	// private functions
	const bool fillRoute();
	void fillGrid();
	void clear();
	const int getRandom(unsigned int) const;
	void fillGridEmptyCells();
	void sortEndPipe();

}; // end Level
