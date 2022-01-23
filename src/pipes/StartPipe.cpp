#include "StartPipe.h"

//===============================================
void StartPipe::turnAroundRight()
{
	switch (m_orientation)
	{
	case int(Numbers::One):
		m_dir._D = true;
		m_dir._U = m_dir._R = m_dir._L = false;
		break;
	case int(Numbers::Two):
		m_dir._L = true;
		m_dir._D = m_dir._U = m_dir._R = false;
		break;
	case int(Numbers::Three):
		m_dir._U = true;
		m_dir._R = m_dir._L = m_dir._D = false;
		break;
	case int(Numbers::Four):
		m_dir._R = true;
		m_dir._D = m_dir._U = m_dir._L = false;
		break;
	}
	Pipe::turnAroundRight();
}

//===============================================
void StartPipe::turnAroundLeft()
{
	switch (m_orientation)
	{
	case int(Numbers::One) :
		m_dir._U = true;
		m_dir._D = m_dir._R = m_dir._L = false;
		break;
	case int(Numbers::Two):
		m_dir._R = true;
		m_dir._D = m_dir._U = m_dir._L = false;
		break;
	case int(Numbers::Three):
		m_dir._D = true;
		m_dir._R = m_dir._L = m_dir._U = false;
		break;
	case int(Numbers::Four):
		m_dir._L = true;
		m_dir._D = m_dir._U = m_dir._R = false;
		break;
	}
	Pipe::turnAroundLeft();
}
