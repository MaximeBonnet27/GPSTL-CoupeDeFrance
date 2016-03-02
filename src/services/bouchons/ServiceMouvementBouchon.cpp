#include "ServiceMouvementBouchon.h"


void ServiceMouvementBouchon::avancer(int puissance){
        Logger::info("ServiceMouvement::avancer");
}

void ServiceMouvementBouchon::reculer(int puissance){
        Logger::info("ServiceMouvement::reculer");
}

void ServiceMouvementBouchon::tourner(int puissance, double angle){
        Logger::info("ServiceMouvement::tourner");
}

void ServiceMouvementBouchon::stopper(){
        Logger::info("ServiceMouvement::stopper");
}

void ServiceMouvementBouchon::faireDemiTour(int puissance){
        Logger::info("ServiceMouvement::demiTour");
}

void ServiceMouvementBouchon::tournerAngleDroitGauche(int puissance){
        Logger::info("ServiceMouvement::tournerAngleDroitGauche");
}
void ServiceMouvementBouchon::tournerAngleDroitDroite(int puissance){
        Logger::info("ServiceMouvement::tournerAngleDroitDroite");
}
