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

int etape = 0;

void Brain::step(){
        if(!aEnvoyeAvancer){
                serviceMouvement->avancer(300);
                aEnvoyeAvancer = true;
        }
        float distance = serviceSonar->distanceObstacle();
        if(!aDetecteObstacle && distance > 0.2 && distance < 0.6){
                serviceMouvement->stopper(300);
                aDetecteObstacle = true;
        }

}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}
