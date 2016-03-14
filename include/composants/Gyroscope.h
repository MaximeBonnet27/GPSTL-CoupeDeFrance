#ifndef GYRO_H_GUARD
#define GYRO_H_GUARD

#include "mbed.h"
#include "ServiceGyroscope.h"
#include "grove_gyroscope_class.h"

/**
 * Composant Gyroscope
 * Offre : ServiceGyroscope
 * Requiert : /
 */

class Gyroscope :
public ServiceGyroscope
{
    private :
    GroveGyroscope* gyroscope;
    float angle;
    public :
    /* Service */
    void init();
    
    /* ServiceGyro */
    float getHeading();
    
};

#endif