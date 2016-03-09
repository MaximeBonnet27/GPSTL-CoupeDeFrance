#include "Moteur.h"
#include "Logger.h"
#include "VNH5019.h"


void Moteur::init(){
        Logger::info("Moteur::init");
        carteMoteur = new DRV8835(PIN_AIN1, PIN_AIN2, PIN_BIN1, PIN_BIN2);
}

void Moteur::avancer(int puissance){
        Logger::info("Moteur::avancer");
        carteMoteur->setVitesse(puissance);
        carteMoteur->setModeMoteur(COTE_DROIT, FORWARD_MODE);
        carteMoteur->setModeMoteur(COTE_GAUCHE, FORWARD_MODE);
}

void Moteur::reculer(int puissance){
        Logger::info("Moteur::reculer");
        carteMoteur->setVitesse(puissance);
        carteMoteur->setModeMoteur(COTE_DROIT, REVERSE_MODE);
        carteMoteur->setModeMoteur(COTE_GAUCHE, REVERSE_MODE);

}

void Moteur::tourner(int puissance, double angle){
        Logger::info("Moteur::tourner");
        carteMoteur->setVitesse(puissance);
        /* TODO A préciser */
        if(angle < 0){ // On tourne a droite
                carteMoteur->setModeMoteur(COTE_DROIT, BRAKE_MODE);
                carteMoteur->setModeMoteur(COTE_GAUCHE, FORWARD_MODE);
        }
        else{ // On tourne a gauche
                carteMoteur->setModeMoteur(COTE_DROIT, FORWARD_MODE);
                carteMoteur->setModeMoteur(COTE_GAUCHE, BRAKE_MODE);
        }
}

void Moteur::stopper(){
        Logger::info("Moteur::stopper");
        carteMoteur->setModeMoteur(COTE_DROIT, BRAKE_MODE);
        carteMoteur->setModeMoteur(COTE_GAUCHE, BRAKE_MODE);

}

void Moteur::faireDemiTour(int puissance){
        Logger::info("Moteur::demiTour");
        /* TODO */
}

void Moteur::tournerAngleDroitGauche(int puissance){
        Logger::info("Moteur::tournerAngleDroitGauche");
        /* TODO */
}
void Moteur::tournerAngleDroitDroite(int puissance){
        Logger::info("Moteur::tournerAngleDroitDroite");
        /* TODO */
}
