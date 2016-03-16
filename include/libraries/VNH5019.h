#ifndef DualVNH5019MotorShield_h
#define DualVNH5019MotorShield_h

#include <mbed.h>

class VNH5019
{
public:
        VNH5019(PinName INA_, PinName INB_, PinName ENDIAG_, PinName CS_, PinName PWM_, int numero);

        // set motor speed from -1.0 to +1.0
        void speed(float Speed);

        // stop (no current to the motors)
        void stop();

        // Brake, with strength 0..1
        void brake(float Brake);

        // returns the current through the motor, in mA
        float get_current_mA();

        // returns true if there has been a fault
        bool is_fault();

        // Clears the fault condition
        // PRECONDITION: is_fault()
        void clear_fault();

        // disable the motor, and set outputs to zero.  This is a low power mode.
        void disable();

        // enable the motor.
        void enable();

        // set the PWM period of oscillation in seconds
        void set_pwm_period(float p)
        { PWM.period(p); }


        int numero;


private:
        void init();

        DigitalOut   INA;
        DigitalOut   INB;
        DigitalInOut ENDIAG;
        AnalogIn     CS;
        PwmOut       PWM;
};

// Helper class for the Pololu dual VNH5019 motor shield.
// The default constructor uses the default arduino pins.
// The motors can be accessed either by .m1 or .m2, or by operator()(i) where i is 1 or 2.
class DualVNH5019MotorShield
{
public:
        // default pin selection
        DualVNH5019MotorShield(); // Default pin selection.


        // User-defined pin selection.
        DualVNH5019MotorShield(PinName INA1_, PinName INB1_, PinName ENDIAG1_, PinName CS1_, PinName PWM1_,
                PinName INA2_, PinName INB2_, PinName ENDIAG2_, PinName CS2_, PinName PWM2_);

                // returns the given motor object, 1 or 2.
                VNH5019& operator()(int m);

                VNH5019 moteur_droite;
                VNH5019 moteur_gauche;
        };

        inline
        void VNH5019::stop()
        {
                INA = 0;
                INB = 0;
                PWM = 0.0;
        }

        inline
        void VNH5019::brake(float Brake)
        {
                // normalize Brake to 0..1
                if (Brake < 0)
                Brake = -Brake;
                if (Brake > 1.0)
                Brake = 1.0;

                INA = 0;
                INB = 0;
                PWM = Brake;
        }

        inline
        float VNH5019::get_current_mA()
        {
                // Scale is 144mV per A
                // Scale factor is 3.3 / 0.144 = 22.916667
                return CS.read() * 22.916667;
        }

        inline
        bool VNH5019::is_fault()
        {
                return !ENDIAG;
        }

        inline
        void VNH5019::disable()
        {
                ENDIAG.output();
                ENDIAG.write(0);
        }

        inline
        void VNH5019::enable()
        {
                ENDIAG.input();
        }

        /* Constructeur par défaut initialisé avec les bons pins */

        inline
        DualVNH5019MotorShield::DualVNH5019MotorShield()
        : moteur_gauche(D2, D4, D6, PA_0, D9, 0),
          moteur_droite(D7, D8, D12, PA_1, D10, 1)
        {}

        inline
        DualVNH5019MotorShield::DualVNH5019MotorShield(PinName INA1_, PinName INB1_, PinName ENDIAG1_, PinName CS1_, PinName PWM1_,
                PinName INA2_, PinName INB2_, PinName ENDIAG2_, PinName CS2_, PinName PWM2_)
                : moteur_droite(INA1_, INB1_, ENDIAG1_, CS1_, PWM1_, 0),
                moteur_gauche(INA2_, INB2_, ENDIAG2_, CS2_, PWM2_, 1)
                {
                }

                inline
                VNH5019&
                DualVNH5019MotorShield::operator()(int m)
                {
                        return m == 0 ? moteur_droite : moteur_gauche;
                }


                #endif
