#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

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


                        int pasCourant;

                        /* Tour de boucle */
                        void step();

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