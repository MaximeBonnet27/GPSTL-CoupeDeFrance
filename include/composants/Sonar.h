#ifndef SONAR_H_GUARD
#define SONAR_H_GUARD

#include "ServiceSonar.h"

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
        public :
                /* Service */
                void init();

                /* ServiceSonar */
                bool aDetecteObstacle();
                double distanceObstacle();

};

/* SERVICE_SONAR_BOUCHON_H_GUARD */
#endif
