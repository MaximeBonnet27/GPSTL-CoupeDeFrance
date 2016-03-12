#include "Gyroscope.h"

/* TODO find out/ see with R&D team if there is a need of the Timer for a fixed rate. */
void Gyroscope::init(){
    this->gyrscope = new GroveGyroscope(D14, D15);
    
    if (!gyro->write_setup()) {
        printf("couldn't write setup\r\n");
        return 0;
    }
    
    gyro->write_zerocalibrate();
    printf("gyro setup done\r\n");
}

/* TODO Replace this with a getHeadingWrapper */
float Gyroscope::angle(){
    return -1f;
}
