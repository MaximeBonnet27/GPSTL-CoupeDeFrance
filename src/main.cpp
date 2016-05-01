#include "mbed.h"

#include "RandomIA.h"
#include "TestBras.h"
#include "Stage1.h"
#include "Brain.h"
#include "Moteur.h"
#include "Sonar.h"
#include "Gyroscope.h"
#include "FeedbackCurrent.h"
#include "Bras.h"

int main(){

        Brain* brain = new Brain();
        Moteur* moteur = new Moteur();
        Sonar* sonarAvant = new Sonar();
        Sonar* sonarArriere = new Sonar();
        Gyroscope* gyroscope = new Gyroscope();
        FeedbackCurrent* feedbackCurrentReader = new FeedbackCurrent();
        Stage1* stage1 = new Stage1(brain);

        /* Initialisations */
        brain->init();
        moteur->init();
        feedbackCurrentReader->init();
        sonarAvant->init(AVANT);
        sonarArriere->init(ARRIERE);
        gyroscope->init();
		//bras->int();

        /* Bindings */
        brain->bindService(moteur);
        brain->bindService(feedbackCurrentReader);
        brain->bindService(sonarAvant);
        brain->bindService(sonarArriere);
        brain->bindService(gyroscope);
        brain->bindService(stage1);
        /* Lancement du brain */

        stage1->init();


        brain->start();

        /* Rajouter delete pour les composants  ??? */

        return EXIT_SUCCESS;
}
