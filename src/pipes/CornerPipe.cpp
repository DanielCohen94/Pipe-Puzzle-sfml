#include "CornerPipe.h"

//===============================================
void CornerPipe::turnAroundRight()
{
	switch (m_orientation)
	{
	case int(Numbers::One):
		m_dir._D = m_dir._R = true;
		m_dir._U = m_dir._L = false;
		break;
	case int(Numbers::Two):
		m_dir._D = m_dir._L = true;
		m_dir._U = m_dir._R = false;
		break;
	case int(Numbers::Three):
		m_dir._U = m_dir._L = true;
		m_dir._D = m_dir._R = false;
		break;
	case int(Numbers::Four):
		m_dir._U = m_dir._R = true;
		m_dir._D = m_dir._L = false;
		break;
	}
	Pipe::turnAroundRight();
}

//===============================================
void CornerPipe::turnAroundLeft()
{
	switch (m_orientation)
	{
	case int(Numbers::One):
		m_dir._D = m_dir._R = false;
		m_dir._U = m_dir._L = true;
		break;
	case int(Numbers::Two):
		m_dir._D = m_dir._L = false;
		m_dir._U = m_dir._R = true;
		break;
	case int(Numbers::Three):
		m_dir._U = m_dir._L = false;
		m_dir._D = m_dir._R = true;
		break;
	case int(Numbers::Four):
		m_dir._U = m_dir._R = false;
		m_dir._D = m_dir._L = true;
		break;
	}
	Pipe::turnAroundLeft();
}
