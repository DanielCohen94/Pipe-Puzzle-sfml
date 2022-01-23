#pragma once
#include "Pipe.h"

class EndPipe : public Pipe {

public:
	//Constructor / Distructor
	EndPipe(const int dir);
	~EndPipe() = default;
	//public functions
	virtual void turnAroundRight()override {};
	virtual void turnAroundLeft()override {};

private:

}; // end EndPipe