#include "TestBras.h"
#include "Brain.h"

TestBras::TestBras(Brain* brain) {
	this->brain = brain;
}

void TestBras::init(){

}

void TestBras::step(){
	if(brain->getServiceBras()->getOuverture() == 0) {
		brain->getServiceBras()->ouvrir(100);
	}
	else {
		brain->getServiceBras()->ouvrir(0);
	}
}

bool TestBras::isFinished(){
	return false;
}
