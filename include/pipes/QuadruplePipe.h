#pragma once
#include "Pipe.h"

class QuadruplePipe : public Pipe {

public:
	//Constructor / Distructor
	QuadruplePipe() :
		Pipe::Pipe(true, true, true, true) {};
	virtual ~QuadruplePipe() = default;
	//public functions
	virtual void turnAroundRight()override {};
	virtual void turnAroundLeft()override {};

private:

}; // end QuadruplePipe