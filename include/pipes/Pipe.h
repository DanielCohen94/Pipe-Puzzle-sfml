#pragma once
#include "Macros.h"
class Pipe {
public:
	struct Directions
	{
		Directions(const bool u, const bool d, const bool l, const bool r) 
			: _U(u), _D(d), _L(l), _R(r) {}
		bool _U;// up down
		bool _D; 
		bool _L;// left right
		bool _R; 
	};
	// Constructor / Distructor
	Pipe(const bool x, const bool y, const bool z, const bool f);
	virtual ~Pipe() = default;
	// public functions
	void setOn() { m_is_on = true; };
	void setOff() { m_is_on = false; };
	const bool getIsOn() { return m_is_on; };
	bool IsConnectionNeighbor(const Pipe&, const Action);
	virtual void turnAroundRight() {
		(m_orientation == int(Numbers::Four)) ? m_orientation = int(Numbers::One) : m_orientation++;
	};
	virtual void turnAroundLeft() {
		(m_orientation == int(Numbers::One)) ? m_orientation = int(Numbers::Four) : m_orientation--;
	};

protected:
	int m_orientation;
	Directions m_dir;
	bool m_is_on;
private:

}; // end Pipe