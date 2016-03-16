#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

#include <cstdlib>
#include <ctime>

#include "mbed.h"

#include "ServiceBrain.h"
#include "ServiceMouvement.h"
#include "ServiceSonar.h"
#include "ServiceGyroscope.h"

/**
* Composant BRAIN
* Offre : ServiceBrain
* Requiert : ServiceMouvement + ServiceSonar + Gyroscope
*/
class Brain :
public ServiceBrain,
public RequiertServiceMouvement,
public RequiertServiceSonar,
public RequiertServiceGyroscope
{

        private :
                /**
                * Pointeurs vers services requis
                */
                ServiceMouvement* serviceMouvement;
                ServiceSonar* serviceSonar;
                ServiceGyroscope* serviceGyroscope;

                /* Compteur de pas global */
                int pasCourant;

                /*** DEPLACEMENT ALEATOIRE ***/

                /*
                 * Automate
                 */
                bool etatAvancer;
                bool etatReculer;
                bool etatTournerGauche;
                bool etatTournerDroite;

                bool transitionVersAvancer;
                bool transitionVersReculer;
                bool transitionVersTournerGauche;
                bool transitionVersTournerDroite;

                /* Compteurs */
                int nbStepsTourner;
                int nbStepsAvancer;

                int stepDebutEtat;

                /*** Fin déplacement aléatoire ***/

                /* Angle Droit */

                bool initAngleDroit;
                float angleInitialAngleDroit;

                /* Tourner */
                bool initTourner;
                float sommeDeltaZ;

                /* Tour de boucle */
                void step();

                /* Commodités pour les déplacements
                * TODO: a implémenter (avec le gyro)
                */

                void faireDemiTour(float puissance);
                void tournerAngleDroitGauche(float puissance);
                void tournerAngleDroitDroite(float puissance);

                void deplacementAleatoire();
                void carre();

                void tourner(float puissance, float angleInDgr);

        public :

                /* Service */
                void init();

                /* ServiceBrain */
                void start();

                /* RequiertServiceMouvement */
                void bindService(ServiceMouvement * serviceMouvement);

                /* RequiertServiceSonar */
                void bindService(ServiceSonar * serviceSonar);

                /* RequiertServiceSonar */
                void bindService(ServiceGyroscope * serviceGyroscope);


};

/* BRAIN_H_GUARD */
#endif
