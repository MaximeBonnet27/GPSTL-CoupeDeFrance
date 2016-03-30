#include "Brain.h"
#include <string>
#include <sstream>
void Brain::init(){

        std::srand(std::time(0));

        pasCourant = 0;
}

void Brain::start(){
    Logger::info("start");
        while(!serviceIA->isFinished()){
                serviceIA->step();
                pasCourant++;
        }
}

void Brain::bindService(ServiceMouvement* serviceMouvement){
        this->serviceMouvement = serviceMouvement;
}

void Brain::bindService(ServiceSonar* serviceSonar){
        this->serviceSonar = serviceSonar;
}

void Brain::bindService(ServiceGyroscope * serviceGyroscope) {
        this->serviceGyroscope = serviceGyroscope;
}

void Brain::bindService(ServiceIA * serviceIA) {
	this->serviceIA = serviceIA;
}


ServiceMouvement* Brain::getServiceMouvement() {
	return this->serviceMouvement;
}

ServiceSonar* Brain::getServiceSonar() {
	return this->serviceSonar;
}

ServiceGyroscope* Brain::getServiceGyroscope() {
	return this->serviceGyroscope;
}

ServiceIA* Brain::getServiceIA() {
	return this->serviceIA;
}

void Brain::bindService(ServiceBras * serviceBras) {
	this->serviceBras = serviceBras;
}

ServiceBras* Brain::getServiceBras() {
	return serviceBras;
}

int Brain::getPasCourant() {
	return pasCourant;
}
