#include <iostream>
#include <exception>
#include "PipePuzzle.h"

int main()
{
	try {
		PipePuzzle().run();
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
	return (EXIT_SUCCESS);
}