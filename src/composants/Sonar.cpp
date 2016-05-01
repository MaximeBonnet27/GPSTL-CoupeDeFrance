#include "Sonar.h"
#include "RangeFinder.h"

void Sonar::init(){
    init(AVANT);
}

/* TODO: vérifier / ajuster les valeurs en dur ici */
void Sonar::init(int position){
        if(position == AVANT){
                this->rangeFinder = new RangeFinder(PC_6, 10, 5800.0, 100000);
        }
        else if(position == ARRIERE){
                this->rangeFinder = new RangeFinder(PC_8, 10, 5800.0, 100000);
        }
}

bool Sonar::aDetecteObstacle(){
    // -1.0 -> rien n'a été détécté par le sonar
    for(int i = 0; i < 5; ++i){
            if(!(distanceObstacle() > 0.2 && distanceObstacle() < 0.3)){
                    return false;
            }
    }
    return true;
}

double Sonar::distanceObstacle(){
    return this->rangeFinder->read_m();
}
