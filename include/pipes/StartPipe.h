#pragma once
#include "Pipe.h"

class StartPipe : public Pipe {

public:
	//Constructor / Distructor
	StartPipe() : 
		Pipe::Pipe(false, false, false, true) {};
	~StartPipe() = default;
	//public functions
	virtual void turnAroundRight()override;
	virtual void turnAroundLeft()override;

private:

}; // end StartPipe