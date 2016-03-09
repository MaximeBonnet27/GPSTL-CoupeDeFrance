#ifndef MOTEUR_H_GUARD
#define MOTEUR_H_GUARD

#include "ServiceMouvement.h"

class VNH5019;
class DualVNH5019MotorShield;

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
                DualVNH5019MotorShield * carteMoteur;

        public :
                /* Service */

                void init();

                /* ServiceMouvement */

                /* Puissances -> periodewidth en microsecondes */

                void avancer(float puissance);
                void reculer(float puissance);
                void tourner(float puissance, double angle);
                void stopper();

                void faireDemiTour(float puissance);
                void tournerAngleDroitGauche(float puissance);
                void tournerAngleDroitDroite(float puissance);
};

/* MOTEUR_H_GUARD */
#endif
