#include "mbed.h"
#include "Parameters.h"

#define PWMGAUCHE D9
#define DIRGAUCHE1 D2
#define DIRGAUCHE2 D4
#define PWMDROITE D10
#define DIRDROITE1 D7
#define DIRDROITE2 D8

PwmOut pwmgauche(PWMGAUCHE);
DigitalOut dirgauche1(DIRGAUCHE1);
DigitalOut dirgauche2(DIRGAUCHE2);
PwmOut pwmdroite(PWMDROITE);
DigitalOut dirdroite1(DIRDROITE1);
DigitalOut dirdroite2(DIRDROITE2);

Moteur::Moteur() {
    pwmgauche.period_us(1000);//A METTRE DANS UN SERVICE DEMARRAGE
    pwmdroite.period_us(1000);//A METTRE DANS UN SERVICE DEMARRAGE
    pwmgauche.pulsewidth_us(0);//A METTRE DANS UN SERVICE DEMARRAGE
    pwmdroite.pulsewidth_us(0);//A METTRE DANS UN SERVICE DEMARRAGE
    dirgauche1=1;//A METTRE DANS UN SERVICE DEMARRAGE
    dirgauche2=0;//A METTRE DANS UN SERVICE DEMARRAGE
    dirdroite1=0;//A METTRE DANS UN SERVICE DEMARRAGE
    dirdroite2=1;//A METTRE DANS UN SERVICE DEMARRAGE
}

void Moteur::avancer(int puissance) { //puissance est un entier entre 1 et 4
    pwmgauche.pulsewidth_us(puissance*200);
    pwmdroite.pulsewidth_us(puissance*200);
    return;
}

void Moteur::stop() {
    pwmgauche.pulsewidth_us(0);
    pwmdroite.pulsewidth_us(0);
    return;
}
