#include "EndPipe.h"

//======================= Constructor ======================
EndPipe::EndPipe(const int dir) :
	Pipe::Pipe(false, false, true, false)
{
	// update directtion (By the connecting route)
	switch (dir) {
		case int(Action::Up):
			m_dir._U = true;
			m_dir._D = m_dir._L = m_dir._R = false;
			break;
		case int(Action::Down):
			m_dir._D = true;
			m_dir._U = m_dir._L = m_dir._R = false;
			break;
		case int(Action::Left):
			m_dir._L = true;
			m_dir._D = m_dir._U = m_dir._R = false;
			break;
		case int(Action::Right):
			m_dir._R = true;
			m_dir._D = m_dir._L = m_dir._U = false;
			break;
	}
}