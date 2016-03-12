#include "Brain.h"
#include "ServiceMouvement.h"
#include "ServiceSonar.h"

void Brain::init(){
        pasCourant = 0;
        aDetecteObstacle = false;
}

void Brain::start(){
        while(true){
                this->step();
        }
}

void Brain::step(){
        if(serviceSonar->aDetecteObstacle()){
                serviceMouvement->stopper();
                aDetecteObstacle = true;
        }
        if(!aDetecteObstacle){
                serviceMouvement->avancer(300);
        }
}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}
