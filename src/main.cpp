#include "mbed.h"

#include "Brain.h"
#include "MoteurBouchon.h"
#include "SonarBouchon.h"

int main(){
        Brain* brain = new Brain();
        MoteurBouchon* moteur = new MoteurBouchon();
        SonarBouchon* sonar = new SonarBouchon();

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
