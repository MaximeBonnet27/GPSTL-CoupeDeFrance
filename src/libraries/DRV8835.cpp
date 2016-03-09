#include "DRV8835.h"

DRV8835::DRV8835(PinName ain1, PinName ain2, PinName bin1, PinName bin2):
pwmAIN1(ain1),
pwmAIN2(ain2),
pwmBIN1(bin1),
pwmBIN2(bin2)
{
        setPeriode(PERIODE_INITIALE);
        setVitesse(VITESSE_INITIALE);
        setModeMoteur(COTE_GAUCHE, BRAKE_MODE);
        setModeMoteur(COTE_DROIT, BRAKE_MODE);
}

void DRV8835::setPeriode(int periode){
        pwmAIN1.period_us(periode);
        pwmAIN2.period_us(periode);
        pwmBIN1.period_us(periode);
        pwmBIN2.period_us(periode);
}

void DRV8835::setVitesse(int vitesse){
        pwmAIN1.pulsewidth_us(vitesse);
        pwmAIN2.pulsewidth_us(vitesse);
        pwmBIN1.pulsewidth_us(vitesse);
        pwmBIN2.pulsewidth_us(vitesse);
}

void DRV8835::setModeMoteur(int cote, int mode){
        if(cote == COTE_GAUCHE){
                switch(mode){
                        case COAST_MODE :
                        pwmAIN1 = 0;
                        pwmAIN2 = 0;
                        break;
                        case REVERSE_MODE :
                        pwmAIN1 = 0;
                        pwmAIN2 = 1;
                        break;
                        case FORWARD_MODE :
                        pwmAIN1 = 1;
                        pwmAIN2 = 0;
                        break;
                        case BRAKE_MODE :
                        pwmAIN1 = 1;
                        pwmAIN2 = 1;
                        break;
                }
        }
        else if (cote == COTE_DROIT){
                switch(mode){
                        case COAST_MODE :
                        pwmBIN1 = 0;
                        pwmBIN2 = 0;
                        break;
                        case REVERSE_MODE :
                        pwmBIN1 = 0;
                        pwmBIN2 = 1;
                        break;
                        case FORWARD_MODE :
                        pwmBIN1 = 1;
                        pwmBIN2 = 0;
                        break;
                        case BRAKE_MODE :
                        pwmBIN1 = 1;
                        pwmBIN2 = 1;
                        break;
                }
        }
}
