#include "Brain.h"

void Brain::init(){
        pasCourant = 0;
}

void Brain::start(){
        while(true){
                this->step();
        }
}

void Brain::step(){
        if(pasCourant >= 10){
                serviceMouvement->stopper();
                return;
        }
        else{
                serviceMouvement->avancer(10);
                return;
        }
        pasCourant++;
}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}
