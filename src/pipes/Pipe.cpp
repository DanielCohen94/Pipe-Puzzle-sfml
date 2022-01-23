#include "Pipe.h"

Pipe::Pipe(const bool u, const bool d, const bool l, const bool r) :
	m_orientation(1),m_dir(u,d,l,r), m_is_on(false)
{}

bool Pipe::IsConnectionNeighbor(const Pipe& pn, const Action act)
{
	auto is_good_neighbor = false;

	if (act == Action::Up)
	{
		if (this->m_dir._U && pn.m_dir._D)
				is_good_neighbor = true;
	}
	else if (act == Action::Down)
	{
		if (this->m_dir._D && pn.m_dir._U)
			is_good_neighbor = true;
	}
	else if (act == Action::Left)
	{
		if (this->m_dir._L && pn.m_dir._R)
			is_good_neighbor = true;
	}
	else if (act == Action::Right)
	{
		if (this->m_dir._R && pn.m_dir._L)
			is_good_neighbor = true;
	}

	return is_good_neighbor;
}
