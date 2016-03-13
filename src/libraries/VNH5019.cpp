#include "VNH5019.h"

VNH5019::VNH5019(PinName INA_, PinName INB_, PinName ENDIAG_, PinName CS_, PinName PWM_, int numero_)
: INA(INA_),
INB(INB_),
ENDIAG(ENDIAG_),
CS(CS_),
PWM(PWM_),
numero(numero_)
{
        this->init();
}

void VNH5019::init()
{
        ENDIAG.input();
        ENDIAG.mode(PullUp);
        // On pourrait tester d'autre valeurs, Bin avait mis 1000.
        PWM.period_us(250);   // 4 kHz (valid 0 - 20 kHz)
        PWM.write(0);

}

void VNH5019::speed(float Speed)
{

        /*
         * Pour avancer
         * moteur droit (numero = 0) : INA -> 0, INB -> 1
         * moteur gauche (numero = 1) : INA -> 1, INB -> 0
         * Contraire pour reculer
         * speed(0) -> roue libre.
         */

        bool Reverse = !numero;

        if (Speed < 0)
        {
                Speed = -Speed;  // Make speed a positive quantity
                Reverse = !Reverse;  // Preserve the direction
        }

        // clamp the speed at maximum
        if (Speed > 1.0)
                Speed = 1.0;

        if (Speed == 0.0)
        {
                INA = 0;
                INB = 0;
                PWM = 0;
        }
        else
        {
                INA = !Reverse;
                INB = Reverse;
                PWM = Speed;
        }
}

void VNH5019::clear_fault()
{
        // if ENDIAG is high, then there is no fault
        if (ENDIAG.read())
        return;

        // toggle the inputs
        INA = 0;
        INB = 0;
        wait_us(250);
        INA = 1;
        INB = 1;
        wait_us(250);

        // pull low all inputs and wait 1600us for t_DEL
        INA = 0;
        INB = 0;
        PWM = 0;
        ENDIAG.output();
        ENDIAG = 0;
        wait_us(1600);

        // and finally re-enable the motor
        ENDIAG.input();
}
