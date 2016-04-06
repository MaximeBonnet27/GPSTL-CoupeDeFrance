#include "Sonar.h"
#include "RangeFinder.h"

void Sonar::init(){
    init(AVANT);
}

/* TODO: vérifier / ajuster les valeurs en dur ici */
void Sonar::init(int position){
        if(position == AVANT){
                this->rangeFinder = new RangeFinder(PC_8, 10, 5800.0, 100000);
        }
        else if(position == ARRIERE){
                this->rangeFinder = new RangeFinder(PC_6, 10, 5800.0, 100000);
        }
}

bool Sonar::aDetecteObstacle(){
    // -1.0 -> rien n'a été détécté par le sonar
    return distanceObstacle() > 0.40 && distanceObstacle() < 0.50;
}

double Sonar::distanceObstacle(){
    return this->rangeFinder->read_m();
}
