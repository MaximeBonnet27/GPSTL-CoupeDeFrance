#ifndef ABSTRACT_IA_H_GUARD
#define ABSTRACT_IA_H_GUARD

#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

#include "ServiceIA.h"
#include "mbed.h"

/* On commence au nord */

#define NORD 0
#define EST 1
#define SUD 2
#define OUEST 3

class Brain;

class Compteur {
public:
        Compteur(PinName pin) : _interrupt(pin) {
                _interrupt.rise(this, &Compteur::increment);
        }
        void increment() {
                _count++;
        }
        int read() {
                return _count;
        }
        void reset() {
                _count=0;
        }
private:
        InterruptIn _interrupt;
        volatile int _count;
};

class AbstractIA : public ServiceIA {
        private :


        bool initTourner;
        float sommeDeltaZ;
        int heading;

        bool initAvancer;
        bool initReculer;

        Compteur* compteurMoteurDroite;
        Compteur* compteurMoteurGauche;

        protected :
        Brain* brain;
        bool finiComportementSimple;

        AbstractIA(Brain* brain);


        public :
        void faireDemiTour(float puissance);
        void tournerAngleDroitGauche(float puissance);
        void tournerAngleDroitDroite(float puissance);

        void tourner(float puissance, float angleInDgr);

        void avancer(float puissance,int pas);
        void reculer(float puissance,int pas);

        int getHeading();

        bool aDetecteObstacleDevant();
        bool aDetecteObstacleDerriere();

};


#endif
