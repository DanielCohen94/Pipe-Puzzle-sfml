#pragma once
#include "Pipe.h"

class CornerPipe : public Pipe {

public:
	//Constructor / Distructor
	CornerPipe() :
		Pipe::Pipe(true, false, false, true) {};
	virtual ~CornerPipe() = default;
	//public functions
	virtual void turnAroundRight()override;
	virtual void turnAroundLeft()override;

private:

}; // end CornerPipe