#include "SonarBouchon.h"
#include "Logger.h"

void SonarBouchon::init(){
        Logger::info("SonarBouchon::init");
}

bool SonarBouchon::aDetecteObstacle(){
        Logger::info("SonarBouchon::aDetecteObstacle");
        return false;
}
double SonarBouchon::distanceObstacle(){
        Logger::info("SonarBouchon::distanceObstacle");
        return 0.0;
}
