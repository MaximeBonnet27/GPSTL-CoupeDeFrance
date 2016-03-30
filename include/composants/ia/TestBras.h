#ifndef TEST_BRAS_H_GUARD
#define TEST_BRAS_H_GUARD

#include "ServiceBras.h"
#include "ServiceIA.h"

class Brain;

class TestBras :
public ServiceIA
{
	private :
		 Brain* brain;
	public :
		 void init();
		 void step();
		 bool isFinished();

 		 TestBras(Brain* brain);
};

#endif
