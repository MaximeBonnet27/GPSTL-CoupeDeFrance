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
        if(angle == DROITE){ // On tourne a droite
                carteMoteur->moteur_droite.speed(-puissance);
                carteMoteur->moteur_gauche.speed(puissance);
        }
        else if(angle == GAUCHE){ // On tourne a gauche
                carteMoteur->moteur_droite.speed(puissance);
                carteMoteur->moteur_gauche.speed(-puissance);
        }
}

void Moteur::stopper(float puissance){
        Logger::info("Moteur::stopper");
        carteMoteur->moteur_droite.brake(puissance);
        carteMoteur->moteur_gauche.brake(puissance);
}

void Moteur::roueLibre(){
        Logger::info("Moteur::roueLibre");
        carteMoteur->moteur_droite.speed(0.0);
        carteMoteur->moteur_gauche.speed(0.0);
}

float Moteur::getIntensiteMoteurDroite(){
        Logger::info("Moteur::getIntensite");
        return carteMoteur->moteur_droite.get_current_mA();
}

float Moteur::getIntensiteMoteurGauche(){
        Logger::info("Moteur::getIntensite");
        return carteMoteur->moteur_droite.get_current_mA();
}
