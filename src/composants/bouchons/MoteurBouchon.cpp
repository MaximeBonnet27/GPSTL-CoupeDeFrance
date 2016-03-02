#include "MoteurBouchon.h"
#include "Logger.h"

void MoteurBouchon::init(){
        Logger::info("MoteurBouchon::init");
}

void MoteurBouchon::avancer(int puissance){
        Logger::info("MoteurBouchon::avancer");
}

void MoteurBouchon::reculer(int puissance){
        Logger::info("MoteurBouchon::reculer");
}

void MoteurBouchon::tourner(int puissance, double angle){
        Logger::info("MoteurBouchon::tourner");
}

void MoteurBouchon::stopper(){
        Logger::info("MoteurBouchon::stopper");
}

void MoteurBouchon::faireDemiTour(int puissance){
        Logger::info("MoteurBouchon::demiTour");
}

void MoteurBouchon::tournerAngleDroitGauche(int puissance){
        Logger::info("MoteurBouchon::tournerAngleDroitGauche");
}
void MoteurBouchon::tournerAngleDroitDroite(int puissance){
        Logger::info("MoteurBouchon::tournerAngleDroitDroite");
}
