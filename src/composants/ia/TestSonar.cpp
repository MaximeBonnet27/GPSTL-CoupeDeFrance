#include "TestSonar.h"
#include "Brain.h"
#include "Logger.h"


TestSonar::TestSonar(Brain * brain){
        this->brain = brain;
        initAvancer = false;
}

void TestSonar::init(){
}

void TestSonar::step(){
        Logger::debug("TestSonar::step");
        if(!initAvancer){
                initAvancer = true;
                brain->getServiceMouvement()->avancer(1.0);
        }
        else {
                if(brain->getServiceSonar()->aDetecteObstacle()){
                        brain->getServiceMouvement()->stopper(1.0);
                }
        }
}
