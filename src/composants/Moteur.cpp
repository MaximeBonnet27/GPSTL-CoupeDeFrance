#include "Moteur.h"
#include "Logger.h"
#include "VNH5019.h"


void Moteur::init(){
        Logger::info("Moteur::init");
        carteMoteur = new DualVNH5019MotorShield();
        carteMoteur->moteur_droite.speed(0);
        carteMoteur->moteur_gauche.speed(0);

}

void Moteur::avancer(float puissance){
        Logger::info("Moteur::avancer");
        carteMoteur->moteur_droite.speed(puissance);
        carteMoteur->moteur_gauche.speed(puissance);
}

void Moteur::reculer(float puissance){
        Logger::info("Moteur::reculer");
        carteMoteur->moteur_droite.speed(-puissance);
        carteMoteur->moteur_gauche.speed(-puissance);

}

void Moteur::tourner(float puissance, double angle){
        Logger::info("Moteur::tourner");
        /* TODO A préciser */
        if(angle < 0){ // On tourne a droite
                carteMoteur->moteur_droite.speed(0);
                carteMoteur->moteur_gauche.speed(puissance);
        }
        else{ // On tourne a gauche
                carteMoteur->moteur_droite.speed(puissance);
                carteMoteur->moteur_gauche.speed(0);
        }
}

void Moteur::stopper(){
        Logger::info("Moteur::stopper");
        carteMoteur->moteur_droite.speed(0);
        carteMoteur->moteur_gauche.speed(0);

}

void Moteur::faireDemiTour(float puissance){
        Logger::info("Moteur::demiTour");
        /* TODO */
}

void Moteur::tournerAngleDroitGauche(float puissance){
        Logger::info("Moteur::tournerAngleDroitGauche");
        /* TODO */
}
void Moteur::tournerAngleDroitDroite(float puissance){
        Logger::info("Moteur::tournerAngleDroitDroite");
        /* TODO */
}
