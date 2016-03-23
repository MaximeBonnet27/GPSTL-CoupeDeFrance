#include "mbed.h"

#include "RandomIA.h"
#include "Brain.h"
#include "Moteur.h"
#include "Sonar.h"
#include "Gyroscope.h"

int main(){

        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Sonar* sonar = new Sonar();
        Gyroscope* gyroscope = new Gyroscope();
		  RandomIA* randomIA = new RandomIA(brain);

        /* Initialisations */
        brain->init();
        moteur->init();
        sonar->init();
        gyroscope->init();
		  randomIA->init();

        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(sonar);
        brain->bindService(gyroscope);
		  brain->bindService(randomIA);
        /* Lancement du brain */
        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
