#include "AbstractIA.h"
#include "Brain.h"

AbstractIA::AbstractIA(Brain* brain){
        this->brain = brain;
        heading = NORD;
        initTourner = false;
        sommeDeltaZ = 0;
        compteurMoteurDroite = new Compteur(PB_14);
        compteurMoteurGauche = new Compteur(PB_13);
        finiComportementSimple = false;
        initAvancer = false;
        initReculer = false;
}


void AbstractIA::faireDemiTour(float puissance){
        finiComportementSimple = false;
        tournerAngleDroitDroite(puissance);
        tournerAngleDroitDroite(puissance);
}
void AbstractIA::tournerAngleDroitGauche(float puissance){
        finiComportementSimple = false;
        tourner(puissance, -90.0);
        heading = (heading + 3) % 4;
}
void AbstractIA::tournerAngleDroitDroite(float puissance){
        finiComportementSimple = false;
        tourner(puissance, 90.0);
        heading = (heading + 1) % 4;
}

void AbstractIA::tourner(float puissance, float angleInDgr){
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
                finiComportementSimple = true;
                sommeDeltaZ = 0;
                initTourner = false;
        }
}

void AbstractIA::avancer(float puissance, int pas){
        if(!initAvancer){
                finiComportementSimple = false;
                compteurMoteurGauche->reset();
                initAvancer = true;
                brain->getServiceMouvement()->avancer(puissance);
        }
        if(compteurMoteurGauche->read() >= pas){
                finiComportementSimple = true;
                brain->getServiceMouvement()->stopper(1.0);
                initAvancer = false;
        }
}

void AbstractIA::reculer(float puissance, int pas){
        if(!initReculer){
                finiComportementSimple = false;
                compteurMoteurGauche->reset();
                initReculer = true;
                brain->getServiceMouvement()->reculer(puissance);
        }
        if(compteurMoteurGauche->read() >= pas){
                finiComportementSimple = true;
                brain->getServiceMouvement()->stopper(1.0);
                initReculer = false;
        }
}

int AbstractIA::getHeading(){
        return heading;
}

bool AbstractIA::aDetecteObstacleDevant(){
        return brain->getServicesSonar()[0]->aDetecteObstacle();
}


bool AbstractIA::aDetecteObstacleDerriere(){
        return brain->getServicesSonar()[1]->aDetecteObstacle();
}
