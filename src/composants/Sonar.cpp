#include "Sonar.h"
#include "RangeFinder.h"

void Sonar::init(PinName pin, int pulsetime, float scale, int timeout){
    this->rangeFinder = new RangeFinder(pin, pulsetime, scale, timeout);
}

bool Sonar::aDetecteObstacle(){
    // -1.0 nothing detected by sensor
    if(this->distanceObstacle() == -1.0) {
        return false;
    }
    return true;
}

double Sonar::distanceObstacle(){
    return this->rangeFinder->read_m();
}
