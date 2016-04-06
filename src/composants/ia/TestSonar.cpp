#include "TestSonar.h"
#include "Brain.h"
#include "Logger.h"


TestSonar::TestSonar(Brain* brain){
        this->brain = brain;
        initAvancer = false;
        MAX_IT = 15;
        it = MAX_IT;
}

void TestSonar::init(){
}

void TestSonar::step(){
        Logger::debug("TestSonar::step");
        if(!initAvancer){
                initAvancer = true;
                brain->getServiceMouvement()->avancer(1.0);
                it = MAX_IT;
        }
        else {
                if(!brain->getServiceSonar()->aDetecteObstacle()){
                    brain->getServiceMouvement()->stopper(1.0);

                    if(it == MAX_IT) {
                        int ouv = brain->getServiceBras()->getOuverture();
                        if(ouv == 100)
                            brain->getServiceBras()->ouvrir(0);
                        else
                            brain->getServiceBras()->ouvrir(100);
                        it--;
                    } else if(it == 0) {
                        it = MAX_IT;
                    } else {
                        it--;
                    }
                } else {
                    initAvancer = false;
                }
        }

        /*bool obstacle = brain->getServiceSonar()->aDetecteObstacle();
        avancer = !obstacle;
        bras = obstacle;

        if(avancer){
            brain->getServiceMouvement()->avancer(1.0);
        }
        if(bras){
            int ouv = brain->getServiceBras()->getOuverture();
            if(ouv == 100) {
                brain->getServiceBras()->ouvrir(0);
            } else {
                brain->getServiceBras()->ouvrir(100);
            }
        }*/
}

bool TestSonar::isFinished(){
    return false;
}
