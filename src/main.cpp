#include "mbed.h"

#include "RandomIA.h"
#include "TestBras.h"
#include "TestSonar.h"
#include "Stage1.h"
#include "Brain.h"
#include "Moteur.h"
#include "Bras.h"
#include "Sonar.h"
#include "Gyroscope.h"
#include "Bras.h"

int main(){

        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Bras* bras = new Bras(PA_11);
        Sonar* sonar = new Sonar();
        Gyroscope* gyroscope = new Gyroscope();
        TestSonar* testSonar = new TestSonar(brain);
		  //Bras* bras = new Bras(D3);
		  //RandomIA* randomIA = new RandomIA(brain);
		  //TestBras* testBras = new TestBras(brain);

        /* Initialisations */
        brain->init();
        moteur->init();
        bras->init();
        sonar->init();
        gyroscope->init();
		//bras->init();
        testSonar->init();
        //randomIA->init();
		//testBras->init();

        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(bras);
        brain->bindService(sonar);
        brain->bindService(gyroscope);
        brain->bindService(testSonar);
		  //brain->bindService(randomIA);
		  //brain->bindService(bras);
		  //brain->bindService(testBras);
        /* Lancement du brain */
        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
