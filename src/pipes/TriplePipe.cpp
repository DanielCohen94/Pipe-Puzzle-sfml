#include "TriplePipe.h"

//===============================================
void TriplePipe::turnAroundRight()
{
	switch (m_orientation)
	{
	case int(Numbers::One):
		m_dir._R = false;
		m_dir._U = m_dir._L = m_dir._D = true;
		break;
	case int(Numbers::Two):
		m_dir._D = false;
		m_dir._U = m_dir._R = m_dir._L = true;
		break;
	case int(Numbers::Three):
		m_dir._L = false;
		m_dir._D = m_dir._R = m_dir._U = true;
		break;
	case int(Numbers::Four):
		m_dir._U = false;
		m_dir._D = m_dir._L = m_dir._R = true;
		break;
	}
	Pipe::turnAroundRight();
}

//===============================================
void TriplePipe::turnAroundLeft()
{
	switch (m_orientation)
	{
	case int(Numbers::One):
		m_dir._L = false;
		m_dir._U = m_dir._R = m_dir._D = true;
		break;
	case int(Numbers::Two):
		m_dir._U = false;
		m_dir._D = m_dir._R = m_dir._L = true;
		break;
	case int(Numbers::Three):
		m_dir._R = false;
		m_dir._D = m_dir._L = m_dir._U = true;
		break;
	case int(Numbers::Four):
		m_dir._D = false;
		m_dir._U = m_dir._L = m_dir._R = true;
		break;
	}
	Pipe::turnAroundLeft();
}
