#include "Brain.h"

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
                serviceMouvement->reculer(1.0);
                aEnvoyeAvancer = true;
        }
        /* TODO : vérifier les valeurs
         * D'après nos obs, de base il est entre 725ma et 750ma
         *
         * Nouvelles observations :
         * Quand on avance, vérifier que intensité > 0.1
         * quand on recule, vérifier que intensité > 0.15 !
         */
        if(etape > 5 && !aEnvoyeReculer
                && (serviceMouvement->getIntensiteMoteurDroite() > 0.15 || serviceMouvement->getIntensiteMoteurGauche() > 0.15)){
                serviceMouvement->avancer(1.0);
                aEnvoyeReculer = true;
        }
        etape++;
        if(etape > 100){
                serviceMouvement->stopper(1.0);
        }
        wait(0.1);
}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}

void Brain::bindService(ServiceGyroscope * serviceGyroscope) {
    this->serviceGyroscope = serviceGyroscope;
}
