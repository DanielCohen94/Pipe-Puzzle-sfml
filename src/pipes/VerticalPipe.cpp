#include "VerticalPipe.h"

//===============================================
void VerticalPipe::turnAroundRight()
{
	turn();
	Pipe::turnAroundRight();
}
//===============================================
void VerticalPipe::turnAroundLeft()
{
	turn();
	Pipe::turnAroundLeft();
}
//============= private functions ====================
void VerticalPipe::turn()
{
	switch (m_orientation)
	{
		case int(Numbers::One) :
			m_dir._U = m_dir._D = false;
			m_dir._L = m_dir._R = true;
			break;
		case int(Numbers::Two) :
			m_dir._U = m_dir._D = true;
			m_dir._L = m_dir._R = false;
			break;
		case int(Numbers::Three) :
			m_dir._U = m_dir._D = false;
			m_dir._L = m_dir._R = true;
			break;
		case int(Numbers::Four) :
			m_dir._U = m_dir._D = true;
			m_dir._L = m_dir._R = false;
			break;
	}
}
