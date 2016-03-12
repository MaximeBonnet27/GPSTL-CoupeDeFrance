#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

#include "mbed.h"

#include "ServiceBrain.h"
#include "ServiceMouvement.h"
#include "ServiceSonar.h"
#include "ServiceGyroscope.h"
/**
 * Composant BRAIN
 * Offre : ServiceBrain
 * Requiert : ServiceMouvement + ServiceSonar
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
    
                        bool aDetecteObstacle;
                        bool aEnvoyeAvancer;

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
    
    /* RequiertServiceSonar */
    void bindService(ServiceGyroscope * serviceGyroscope);
    

};

/* BRAIN_H_GUARD */
#endif
