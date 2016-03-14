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
                carteMoteur->moteur_droite.brake(1.0);
                carteMoteur->moteur_gauche.speed(puissance);
        }
        else{ // On tourne a gauche
                carteMoteur->moteur_droite.speed(puissance);
                carteMoteur->moteur_gauche.brake(1.0);
        }
}

void Moteur::stopper(float puissance){
        Logger::info("Moteur::stopper");
        carteMoteur->moteur_droite.brake(puissance);
        carteMoteur->moteur_gauche.brake(puissance);
}
