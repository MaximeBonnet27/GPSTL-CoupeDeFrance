#ifndef MOTEUR_BOUCHON_H_GUARD
#define MOTEUR_BOUCHON_H_GUARD

#include "Moteur.h"

/**
 * Bouchon pour le composant MOTEUR
 */

 class MoteurBouchon :
        public Moteur
{
        private :
                /* A remplir avec pins etc. */

        public :
                /* Service */

                void init();

                /* ServiceMouvement */

                void avancer(int puissance);
                void reculer(int puissance);
                void tourner(int puissance, double angle);
                void stopper();
};

/* MOTEUR_BOUCHON_H_GUARD */
#endif
