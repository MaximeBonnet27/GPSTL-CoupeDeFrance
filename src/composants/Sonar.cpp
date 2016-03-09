#include "Sonar.h"
#include "RangeFinder.h"

void Sonar::init(){
    this->rangeFinder = new RangeFinder(PC_6, 10, 5800.0, 100000);
}

bool Sonar::aDetecteObstacle(){
    // -1.0 -> rien n'a été détécté par le sonar
    if(this->distanceObstacle() == -1.0) {
        return false;
    }
    return true;
}

double Sonar::distanceObstacle(){
    return this->rangeFinder->read_m();
}
