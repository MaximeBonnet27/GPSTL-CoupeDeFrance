#ifndef SONAR_BOUCHON_H_GUARD
#define SONAR_BOUCHON_H_GUARD

#include "Sonar.h"

/**
 * Composant Sonar
 * Offre : ServiceSonar
 * Requiert : /
 */

class SonarBouchon :
        public Sonar
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

/* SONAR_BOUCHON_H_GUARD */
#endif
