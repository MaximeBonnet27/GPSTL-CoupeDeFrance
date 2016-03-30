#include "mbed.h"

#include "RandomIA.h"
#include "TestBras.h"
#include "Stage1.h"
#include "Brain.h"
#include "Moteur.h"
#include "Sonar.h"
#include "Gyroscope.h"
#include "Bras.h"

int main(){

        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Sonar* sonar = new Sonar();
        Gyroscope* gyroscope = new Gyroscope();
        Stage1* stage1 = new Stage1(brain);
		  //Bras* bras = new Bras(D3);
		  //RandomIA* randomIA = new RandomIA(brain);
		  //TestBras* testBras = new TestBras(brain);

        /* Initialisations */
        brain->init();
        moteur->init();
        sonar->init();
        gyroscope->init();
		//bras->init();
        stage1->init();
        //randomIA->init();
		//testBras->init();

        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(sonar);
        brain->bindService(gyroscope);
        brain->bindService(stage1);
		  //brain->bindService(randomIA);
		  //brain->bindService(bras);
		  //brain->bindService(testBras);
        /* Lancement du brain */
        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
