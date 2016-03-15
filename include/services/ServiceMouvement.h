
#ifndef SERVICE_MOUVEMENT_H_GUARD
#define SERVICE_MOUVEMENT_H_GUARD

#include "Service.h"


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
};

/* SERVICE_MOUVEMENT_H_GUARD */
#endif
