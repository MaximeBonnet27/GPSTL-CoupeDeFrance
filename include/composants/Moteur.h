#ifndef MOTEUR_H_GUARD
#define MOTEUR_H_GUARD

#include "ServiceMouvement.h"

/**
 * Composant MOTEUR
 * Offre : ServiceMouvement
 * Requiert : /
 */

 class Moteur :
        public ServiceMouvement
{
        private :
                /* A remplir avec pins etc. */

        public :
                /* Service */

                void init();

                /* ServiceMouvement */

                void avancer(int puissance);
                void reculer(int puissance);
                void tourner(int puissance, double angle);
                void stopper();

                void faireDemiTour(int puissance);
                void tournerAngleDroitGauche(int puissance);
                void tournerAngleDroitDroite(int puissance);
};

/* MOTEUR_H_GUARD */
#endif
