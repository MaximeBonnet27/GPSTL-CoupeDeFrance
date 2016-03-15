#ifndef MOTEUR_H_GUARD
#define MOTEUR_H_GUARD

#include "ServiceMouvement.h"

#define SEUIL_COLLISION_AVANT (0.1)
#define SEUIL_COLLISION_ARRIERE (0.15)
#define STEP_AVANT_CHECK_COLLISION 5

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

                /* Puissances -> POURCENTAGE */

                void avancer(float puissance);
                void reculer(float puissance);
                void tourner(float puissance, double angle);
                void stopper(float puissance);
                void roueLibre();


                float getIntensiteMoteurDroite();
                float getIntensiteMoteurGauche();

};

/* MOTEUR_H_GUARD */
#endif
