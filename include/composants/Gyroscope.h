#ifndef GYRO_H_GUARD
#define GYRO_H_GUARD

#include "mbed.h"

#include "grove_gyroscope_class.h"
#include "ServiceGyroscope.h"


class RangeFinder;

/**
 * Composant Gyroscope
 * Offre : ServiceGyroscope
 * Requiert : /
 */

class Gyroscope :
public ServiceGyroscope
{
    private :
    GroveGryoscope* gyroscope;
    public :
    /* Service */
    void init();
    
    /* ServiceGyro*/
     
    float angle();
    
};

#endif