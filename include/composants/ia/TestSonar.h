#ifndef TEST_SONAR_H_GUARD
#define TEST_SONAR_H_GUARD

#include "ServiceSonar.h"
#include "ServiceIA.h"

class Brain;

class TestSonar :
public ServiceIA
{
	private :
		Brain* brain;
        bool initAvancer;
		int it;
		int MAX_IT;
	public :
		 void init();
		 void step();
		 bool isFinished();

 		 TestSonar(Brain* brain);
};

#endif
