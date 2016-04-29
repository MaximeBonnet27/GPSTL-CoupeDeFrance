
#ifndef SERVICE_MOUVEMENT_H_GUARD
#define SERVICE_MOUVEMENT_H_GUARD

#include "Service.h"

#define SEUIL_COLLISION_AVANT (0.40)
#define SEUIL_COLLISION_ARRIERE (0.15)
#define STEP_AVANT_CHECK_COLLISION 5

#define DROITE (-1)
#define GAUCHE 1

class ServiceMouvement : public Service {
        public :
                /*
                * Fonctionnalités "natives"
                */
                virtual void avancer(float puissance) = 0;
                virtual void reculer(float puissance) = 0;
                virtual void tourner(float puissance, double angle) = 0;
                virtual void stopper(float puissance) = 0;
                virtual void roueLibre() = 0;

                /* Renvoie l'intensité du moteur en milliampères */

                virtual float getIntensiteMoteurDroite() = 0;
                virtual float getIntensiteMoteurGauche() = 0;



};

/**
* Service Binding
*/

class RequiertServiceMouvement {
        public :
                virtual void bindService(ServiceMouvement* serviceMouvement) = 0;
					 virtual ServiceMouvement* getServiceMouvement() = 0;
};

/* SERVICE_MOUVEMENT_H_GUARD */
#endif
