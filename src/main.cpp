#include "mbed.h"

#include "Brain.h"
#include "Moteur.h"
#include "Sonar.h"
#include "Gyroscope.h"

int main(){
        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Sonar* sonar = new Sonar();
        Gyroscope* gyroscope = new Gyroscope();
    
        /* Initialisations */
        brain->init();
        moteur->init();
        sonar->init();
        gyroscope->init();
    
        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(sonar);
        brain->bindService(gyroscope);
    
        /* Lancement du brain */
        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
