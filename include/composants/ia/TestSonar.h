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
	public :
		 void init();
		 void step();

 		 TestSonar(Brain* brain);
};

#endif
