#ifndef DRV8835_H_GUARD
#define DRV8835_H_GUARD

#include "mbed.h"

/* Definition des modes du moteur */

#define COAST_MODE 0
#define REVERSE_MODE 1
#define FORWARD_MODE 2
#define BRAKE_MODE 3

/* Paramètres par défaut */

#define PERIODE_INITIALE (0.001)
#define VITESSE_INITIALE (300)

/* Cotés */

#define COTE_GAUCHE 0
#define COTE_DROIT 1

/* PINS */

#define PIN_AIN1 10
#define PIN_AIN2 9
#define PIN_BIN1 8
#define PIN_BIN2 7

class DRV8835 {
        public :
                PwmOut pwmAIN1;
                PwmOut pwmAIN2;
                PwmOut pwmBIN1;
                PwmOut pwmBIN2;

                /* Constructeur
                 */
                DRV8835(PinName ain1, PinName ain2, PinName bin1, PinName bin2);

                /* Règle la période en microsecondes des pwm */
                void setPeriode(int periode);

                /* Règle la vitesse = pulsewidth (microsecondes) */
                void setVitesse(int vitesse);

                /* Règle le mode du moteur, avec en paramètre l'un des modes définis dans ce fichier */
                void setModeMoteur(int cote, int mode);

};


/* DRV8835_H_GUARD */
#endif
