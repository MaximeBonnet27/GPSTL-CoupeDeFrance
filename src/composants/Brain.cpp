#include "Brain.h"
#include "ServiceMouvement.h"
#include "ServiceSonar.h"

void Brain::init(){
        pasCourant = 0;
        aDetecteObstacle = false;
        aEnvoyeAvancer = false;
}

void Brain::start(){
        while(true){
                this->step();
        }
}

void Brain::step(){
        if(!aEnvoyeAvancer){
                serviceMouvement->avancer(300);
                aEnvoyeAvancer = true;
        }
        if(!aDetecteObstacle && serviceSonar->aDetecteObstacle()){
                serviceMouvement->stopper(300);
                aDetecteObstacle = true;
        }
        wait(0.1);
}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}
