#ifndef RANDOM_IA_H_GUARD
#define RANDOM_IA_H_GUARD

#include "ServiceMouvement.h"
#include "ServiceIA.h"

class Brain;

class RandomIA :
public ServiceIA
{
	private :
		
		 /*** DEPLACEMENT ALEATOIRE ***/

       /*
        * Automate
        */
       bool etatAvancer;
       bool etatReculer;
       bool etatTournerGauche;
       bool etatTournerDroite;

       bool transitionVersAvancer;
       bool transitionVersReculer;
       bool transitionVersTournerGauche;
       bool transitionVersTournerDroite;

       /* Compteurs */
       int nbStepsTourner;
       int nbStepsAvancer;

       int stepDebutEtat;

       /*** Fin déplacement aléatoire ***/

       /* Angle Droit */

       bool initAngleDroit;
       float angleInitialAngleDroit;

       /* Tourner */
       bool initTourner;
       float sommeDeltaZ;


       /* Commodités pour les déplacements
       * TODO: a implémenter (avec le gyro)
       */

       void faireDemiTour(float puissance);
       void tournerAngleDroitGauche(float puissance);
       void tournerAngleDroitDroite(float puissance);

       void deplacementAleatoire();
       void carre();

       void tourner(float puissance, float angleInDgr);

		 Brain* brain;
	public :
		 void init();
		 void step();

 		 RandomIA(Brain* brain);
};

#endif
