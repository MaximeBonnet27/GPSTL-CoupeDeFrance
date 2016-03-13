#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

#include "mbed.h"

#include "ServiceBrain.h"
#include "ServiceMouvement.h"
#include "ServiceSonar.h"

/**
 * Composant BRAIN
 * Offre : ServiceBrain
 * Requiert : ServiceMouvement + ServiceSonar
 */
class Brain :
        public ServiceBrain,
        public RequiertServiceMouvement,
        public RequiertServiceSonar
{

                private :
                        /**
                         * Pointeurs vers services requis
                         */
                        ServiceMouvement* serviceMouvement;
                        ServiceSonar* serviceSonar;

                        bool aDetecteObstacle;
                        bool aEnvoyeAvancer;

                        int pasCourant;

                        /* Tour de boucle */
                        void step();

                        /* Commodités pour les déplacements
                         * TODO: a implémenter (avec le gyro)
                         */

                        void faireDemiTour(float puissance);
                        void tournerAngleDroitGauche(float puissance);
                        void tournerAngleDroitDroite(float puissance);


                public :

                        /* Service */
                        void init();

                        /* ServiceBrain */
                        void start();

                        /* RequiertServiceMouvement */
                        void bindService(ServiceMouvement * serviceMouvement);

                        /* RequiertServiceSonar */
                        void bindService(ServiceSonar * serviceSonar);

};

/* BRAIN_H_GUARD */
#endif
