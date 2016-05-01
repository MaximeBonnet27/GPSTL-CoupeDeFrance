#include "RandomIA.h"
#include "Brain.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

RandomIA::RandomIA(Brain* brain) {
	this->brain = brain;
}

void RandomIA::init(){

        /* Automate Aléatoire */
        transitionVersAvancer = true;
        transitionVersReculer = false;
        transitionVersTournerDroite = false;
        transitionVersTournerGauche = false;

        etatAvancer = false;
        etatReculer = false;
        etatTournerGauche = false;
        etatTournerDroite = false;

        nbStepsAvancer = 15;
        nbStepsTourner = 5;

        stepDebutEtat = 0;
        /* Fin Automate Aléatoire */

        /* Virages */
        sommeDeltaZ = 0;
        initTourner = false;

        initAngleDroit = false;
}

void RandomIA::step(){
        carre();
}

void RandomIA::carre(){
        if(transitionVersAvancer){
                etatAvancer = true;
                etatTournerDroite = false;
        }else if(transitionVersTournerDroite){
                etatAvancer = false;
                etatTournerDroite = true;

        }

        if(etatAvancer){
                if(transitionVersAvancer){
                        brain->getServiceMouvement()->avancer(1.0);
                        stepDebutEtat = brain->getPasCourant();
                        transitionVersAvancer = false;
                }

                if(brain->getPasCourant() - stepDebutEtat >= nbStepsAvancer){
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

void RandomIA::deplacementAleatoire(){
        /* Transitions */
        if(transitionVersAvancer){
                nbStepsAvancer = 5 + rand() % 15;
                stepDebutEtat = brain->getPasCourant();
                etatAvancer = true;
        }
        else if (transitionVersReculer){
                nbStepsAvancer = 5 + rand() % 5;
                stepDebutEtat = brain->getPasCourant();
                etatReculer = true;
        }
        else if (transitionVersTournerGauche){
                stepDebutEtat = brain->getPasCourant();
                etatTournerGauche = true;
        }
        else if (transitionVersTournerDroite){
                stepDebutEtat = brain->getPasCourant();
                etatTournerDroite = true;
        }

        /* Que faire ? */
        if(etatAvancer){

                int dureeEtat = brain->getPasCourant() - stepDebutEtat;

                /* On vient d'arriver dans cet état */
                if(transitionVersAvancer){
                        transitionVersAvancer = false;
                        brain->getServiceMouvement()->avancer(1.0);
                }

                bool aDetecteObstacle = brain->getServiceSonar()->aDetecteObstacle();

                bool bloque = (dureeEtat > STEP_AVANT_CHECK_COLLISION)
                && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > SEUIL_COLLISION_AVANT
                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > SEUIL_COLLISION_AVANT);

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

                int dureeEtat = brain->getPasCourant() - stepDebutEtat;


                if(transitionVersReculer){
                        transitionVersReculer = false;
                        brain->getServiceMouvement()->reculer(1.0);
                }

                bool bloque = (dureeEtat > STEP_AVANT_CHECK_COLLISION)
                && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > SEUIL_COLLISION_ARRIERE
                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > SEUIL_COLLISION_ARRIERE);

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
                        brain->getServiceMouvement()->tourner(1.0, DROITE);
                }

                bool aDetecteObstacle = brain->getServiceSonar()->aDetecteObstacle();
                if(aDetecteObstacle){
                        transitionVersReculer = true;
                        etatTournerDroite = false;
                }
                else if(brain->getPasCourant() - stepDebutEtat >= nbStepsTourner){
                        transitionVersAvancer = true;
                        etatTournerDroite = false;
                }



        }
        else if(etatTournerGauche){
                if(transitionVersTournerGauche){
                        transitionVersTournerGauche = false;
                        brain->getServiceMouvement()->tourner(1.0, GAUCHE);
                }
                bool aDetecteObstacle = brain->getServiceSonar()->aDetecteObstacle();
                if(aDetecteObstacle){
                        transitionVersReculer = true;
                        etatTournerGauche = false;
                }
                else if(brain->getPasCourant() - stepDebutEtat >= nbStepsTourner){
                        transitionVersAvancer = true;
                        etatTournerGauche = false;
                }
        }
}

void RandomIA::tournerAngleDroitGauche(float puissance){
        tourner(puissance, -90.0);
}
void RandomIA::tournerAngleDroitDroite(float puissance){
        tourner(puissance, 90.0);
}

void RandomIA::tourner(float puissance, float angleInDgr){
        float x, y, z;
        if(!initTourner){
                sommeDeltaZ = 0;
                if(angleInDgr > 0){
                        brain->getServiceMouvement()->tourner(puissance, DROITE);
                }
                else{
                        brain->getServiceMouvement()->tourner(puissance, GAUCHE);
                }
                initTourner = true;
        }

        float angle = fabs(angleInDgr);
        brain->getServiceGyroscope()->read_gyroscope(&x, &y, &z);
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
