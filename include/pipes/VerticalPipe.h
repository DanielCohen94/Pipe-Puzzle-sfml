#pragma once
#include "Pipe.h"

class VerticalPipe : public Pipe {

public:
	//Constructor / Distructor
	VerticalPipe() :
		Pipe::Pipe(true, true, false, false) {};
	virtual ~VerticalPipe() = default;
	//public functions
	virtual void turnAroundRight()override;
	virtual void turnAroundLeft()override;

private:
	// private functions
	void turn();
}; // end CornerPipe