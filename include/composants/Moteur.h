#ifndef MOTEUR_H_GUARD
#define MOTEUR_H_GUARD

#include "ServiceMouvement.h"
#include "DRV8835.h"

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
                DRV8835 * carteMoteur;

        public :
                /* Service */

                void init();

                /* ServiceMouvement */

                /* Puissances -> periodewidth en microsecondes */

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
