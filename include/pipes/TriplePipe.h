#pragma once
#include "Pipe.h"

class TriplePipe : public Pipe {

public:
	//Constructor / Distructor
	TriplePipe() :
		Pipe::Pipe(false, true, true, true) {};
	virtual ~TriplePipe() = default;
	//public functions
	virtual void turnAroundRight()override;
	virtual void turnAroundLeft()override;

private:

}; // end TriplePipe