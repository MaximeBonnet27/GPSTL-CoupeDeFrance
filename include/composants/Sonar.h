#ifndef SONAR_H_GUARD
#define SONAR_H_GUARD

#include "mbed.h"
#include "ServiceSonar.h"

#define AVANT 0
#define ARRIERE 1

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
                /* Initialise le sonar AVANT */
                void init();

                /* Initialise le sonar avec la position donnée en paramètre */
                void init(int position);

                /* ServiceSonar */
                bool aDetecteObstacle();
                double distanceObstacle();

};

/* SERVICE_SONAR_BOUCHON_H_GUARD */
#endif
