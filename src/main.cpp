#include "mbed.h"

#include "Brain.h"
#include "Moteur.h"
#include "Sonar.h"

int main(){
        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Sonar* sonar = new Sonar();

        /* Initialisations */
        brain->init();
        moteur->init();
        sonar->init();

        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(sonar);

        /* Lancement du brain */
        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
