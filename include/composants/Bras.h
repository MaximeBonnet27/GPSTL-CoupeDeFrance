#ifndef BRAS_H_GUARD
#define BRAS_H_GUARD

#include "mbed.h"
#include "ServiceBras.h"

#define MIN_VALUE 900
#define MAX_VALUE 2100

/**
 * Composant Gyroscope
 * Offre : ServiceGyroscope
 * Requiert : /
 */

class Bras :
public ServiceBras
{
    private :

		PwmOut* pwm;
    	// Ouverture
    	int ouverture;
	 	PinName pinMode;
    public :
    /* Service */
    void init();

    /* ServiceBras */
	 virtual void ouvrir(int pourcentage);
	 virtual int getOuverture();

	 Bras(PinName pinMode);



};

#endif
