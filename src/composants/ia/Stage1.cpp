#include "Stage1.h"
#include "Brain.h"

Stage1::Stage1(Brain* brain) {
    this->brain = brain;
}

void Stage1::init(){
    currentState = ETAT_NONE;
    currentTransition = TRANSITION_AVANCER;
    nbPasAvancer1 = 10000000;
    nbPasReculer1 = 5000000;
}

void Stage1::step(){

    switch (currentTransition) {
        case TRANSITION_AVANCER:
        Logger::info("TRANSITION_AVANCER");
            currentState = ETAT_AVANCER;
            debState = brain->getPasCourant();
            break;
        case TRANSITION_RECULER:
        Logger::info("TRANSITION_RECULER");
            currentState = ETAT_RECULER;
            debState = brain->getPasCourant();
            break;
        case TRANSITION_STOP:
        Logger::info("TRANSITION_STOP");
            currentState = ETAT_STOP;
            break;
    }

    switch (currentState) {
        case ETAT_AVANCER:
            if(currentTransition){
                brain->getServiceMouvement()->avancer(1.0);
                currentTransition = 0;
            }
            if(brain->getPasCourant() - debState >= nbPasAvancer1) {
                currentTransition = TRANSITION_RECULER;
            }
            break;
        case ETAT_RECULER:
            if(currentTransition){
                brain->getServiceMouvement()->reculer(1.0);
                currentTransition = 0;
            }
            if(brain->getPasCourant() - debState >= nbPasReculer1) {
                currentTransition = TRANSITION_STOP;
            }
            break;
        case ETAT_STOP:
            brain->getServiceMouvement()->stopper(1.0);
            break;
    }
}

bool Stage1::isFinished(){
    return (currentState == ETAT_STOP);
}
