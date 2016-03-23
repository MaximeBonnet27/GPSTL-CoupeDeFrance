#include "Brain.h"
#include <string>
#include <sstream>
void Brain::init(){

        std::srand(std::time(0));

        pasCourant = 0;
        /* Automate Aléatoire */
        transitionVersAvancer = true;
        transitionVersReculer = false;
        transitionVersTournerDroite = false;
        transitionVersTournerGauche = false;

        etatAvancer = false;
        etatReculer = false;
        etatTournerGauche = false;
        etatTournerDroite = false;

        nbStepsAvancer = 3;
        nbStepsTourner = 5;

        stepDebutEtat = 0;
        /* Fin Automate Aléatoire */

        /* Virages */
        sommeDeltaZ = 0;
        initTourner = false;

        initAngleDroit = false;


}

void Brain::start(){
        timer.start();
        while(true){
            this->step();
        }
}

void Brain::step(){
        carre();
}

void Brain::carre(){
        if(transitionVersAvancer){
                etatAvancer = true;
                etatTournerDroite = false;
        }else if(transitionVersTournerDroite){
                etatAvancer = false;
                etatTournerDroite = true;

        }

        if(etatAvancer){
                if(transitionVersAvancer){
                        serviceMouvement->avancer(1.0);
                        stepDebutEtat = timer.read();
                        transitionVersAvancer = false;
                }

                if(timer.read() - stepDebutEtat >= nbStepsAvancer){
                        etatAvancer = false;
                        transitionVersTournerDroite = true;
                }
        }
        else if(etatTournerDroite){
                tournerAngleDroitDroite(0.75);
                if(!initTourner){
                        etatTournerDroite = false;
                        transitionVersTournerDroite = false;
                        transitionVersAvancer = true;
                }
        }
}

void Brain::deplacementAleatoire(){
        /* Transitions */
        if(transitionVersAvancer){
                nbStepsAvancer = 5 + rand() % 15;
                stepDebutEtat = pasCourant;
                etatAvancer = true;
        }
        else if (transitionVersReculer){
                nbStepsAvancer = 5 + rand() % 5;
                stepDebutEtat = pasCourant;
                etatReculer = true;
        }
        else if (transitionVersTournerGauche){
                stepDebutEtat = pasCourant;
                etatTournerGauche = true;
        }
        else if (transitionVersTournerDroite){
                stepDebutEtat = pasCourant;
                etatTournerDroite = true;
        }

        /* Que faire ? */
        if(etatAvancer){

                int dureeEtat = pasCourant - stepDebutEtat;

                /* On vient d'arriver dans cet état */
                if(transitionVersAvancer){
                        transitionVersAvancer = false;
                        serviceMouvement->avancer(1.0);
                }

                bool aDetecteObstacle = serviceSonar->aDetecteObstacle();

                bool bloque = (dureeEtat > STEP_AVANT_CHECK_COLLISION)
                && (serviceMouvement->getIntensiteMoteurDroite() > SEUIL_COLLISION_AVANT
                || serviceMouvement->getIntensiteMoteurGauche() > SEUIL_COLLISION_AVANT);

                int tirage = rand() % 100;

                if(bloque){
                        transitionVersReculer = true;
                        etatAvancer = false;
                }

                else if(aDetecteObstacle){
                        if(tirage >= 66){
                                transitionVersReculer = true;
                                etatAvancer = false;
                        }
                        else if(tirage >= 33){
                                transitionVersTournerDroite = true;
                                etatAvancer = false;
                        }
                        else {
                                transitionVersTournerGauche = true;
                                etatAvancer = false;
                        }
                }
                /* Il faut changer d'état */
                else if(dureeEtat >= nbStepsAvancer){
                        if(tirage >= 66){
                                transitionVersReculer = true;
                                etatAvancer = false;
                        }
                        else if(tirage >= 33){
                                transitionVersTournerDroite = true;
                                etatAvancer = false;
                        }
                        else {
                                transitionVersTournerGauche = true;
                                etatAvancer = false;
                        }
                }
        }
        else if(etatReculer){

                int dureeEtat = pasCourant - stepDebutEtat;


                if(transitionVersReculer){
                        transitionVersReculer = false;
                        serviceMouvement->reculer(1.0);
                }

                bool bloque = (dureeEtat > STEP_AVANT_CHECK_COLLISION)
                && (serviceMouvement->getIntensiteMoteurDroite() > SEUIL_COLLISION_ARRIERE
                || serviceMouvement->getIntensiteMoteurGauche() > SEUIL_COLLISION_ARRIERE);

                int tirage = rand() % 100;

                if(bloque){
                        transitionVersAvancer = true;
                        etatReculer = false;
                }
                else if(dureeEtat >= nbStepsAvancer){
                        if(tirage >= 50){
                                transitionVersTournerDroite = true;
                                etatReculer = false;
                        }
                        else{
                                transitionVersTournerGauche = true;
                                etatReculer = false;

                        }
                }


        }
        else if(etatTournerDroite){
                if(transitionVersTournerDroite){
                        transitionVersTournerDroite = false;
                        serviceMouvement->tourner(1.0, DROITE);
                }

                bool aDetecteObstacle = serviceSonar->aDetecteObstacle();
                if(aDetecteObstacle){
                        transitionVersReculer = true;
                        etatTournerDroite = false;
                }
                else if(pasCourant - stepDebutEtat >= nbStepsTourner){
                        transitionVersAvancer = true;
                        etatTournerDroite = false;
                }



        }
        else if(etatTournerGauche){
                if(transitionVersTournerGauche){
                        transitionVersTournerGauche = false;
                        serviceMouvement->tourner(1.0, GAUCHE);
                }
                bool aDetecteObstacle = serviceSonar->aDetecteObstacle();
                if(aDetecteObstacle){
                        transitionVersReculer = true;
                        etatTournerGauche = false;
                }
                else if(pasCourant - stepDebutEtat >= nbStepsTourner){
                        transitionVersAvancer = true;
                        etatTournerGauche = false;
                }
        }
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

void Brain::tournerAngleDroitGauche(float puissance){
        tourner(puissance, -90.0);
}
void Brain::tournerAngleDroitDroite(float puissance){
        tourner(puissance, 90.0);
}

void Brain::tourner(float puissance, float angleInDgr){
        float x, y, z;
        if(!initTourner){
                sommeDeltaZ = 0;
                if(angleInDgr > 0){
                        serviceMouvement->tourner(puissance, DROITE);
                }
                else{
                        serviceMouvement->tourner(puissance, GAUCHE);
                }
                initTourner = true;
        }

        float angle = fabs(angleInDgr);
        serviceGyroscope->read_gyroscope(&x, &y, &z);
        std::ostringstream ss;
        ss << sommeDeltaZ;
        Logger::info("Current angle: " + std::string(ss.str()));

        if(sommeDeltaZ < angle){
                sommeDeltaZ += fabs(z);
        }
        else{
                sommeDeltaZ = 0;
                initTourner = false;
        }

}
