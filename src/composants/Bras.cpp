#include "Bras.h"

Bras::Bras(PinName pinMode) {
	this->pinMode = pinMode;
}

void Bras::init(){
    pwm = new PwmOut(pinMode);

	 pwm->period_ms(20);
    pwm->pulsewidth_us(MIN_VALUE);
}

void Bras::ouvrir(int pourcentage) {
	this->ouverture = pourcentage;

	int pulseValue = MIN_VALUE + (pourcentage/100 * (MAX_VALUE - MIN_VALUE));
	pwm->pulsewidth_us(pulseValue);
}

int Bras::getOuverture() {
	return this->ouverture;
}

