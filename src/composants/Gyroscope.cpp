#include "Gyroscope.h"

/* TODO find out/ see with R&D team if there is a need of the Timer for a fixed rate. */
void Gyroscope::init(){
    this->gyroscope = new GroveGyroscope(D14, D15);

    if (!this->gyroscope->write_setup()) {
        printf("couldn't write setup\r\n");
        return;
    }

    this->gyroscope->write_zerocalibrate();
    printf("gyro setup done\r\n");
    this->angle = 0;

    wait(3);

}

float Gyroscope::getHeading(){

    float x, y, z;
    this->gyroscope->read_gyroscope(&x, &y, &z);
    this->angle += z;

    return this->angle;
}

bool Gyroscope::read_gyroscope(float *gx, float *gy, float *gz){
        gyroscope->read_gyroscope(gx, gy, gz);
}
