#ifndef SONAR_H_GUARD
#define SONAR_H_GUARD

#include "mbed.h"
#include "ServiceSonar.h"

class RangeFinder;

/**
 * Composant Sonar
 * Offre : ServiceSonar
 * Requiert : /
 */

class Sonar :
        public ServiceSonar
{
        private :
                /* A remplir avec pins etc. */
                RangeFinder* rangeFinder;
        public :
                /* Service */
                void init(PinName pin, int pulsetime, float scale, int timeout);

                /* ServiceSonar */
                bool aDetecteObstacle();
                double distanceObstacle();

};

/* SERVICE_SONAR_BOUCHON_H_GUARD */
#endif
