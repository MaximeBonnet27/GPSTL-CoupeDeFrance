#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

#include <cstdlib>
#include <ctime>

#include "mbed.h"

#include "ServiceMouvement.h"
#include "ServiceSonar.h"
#include "ServiceGyroscope.h"
#include "ServiceIA.h"

/**
* Composant BRAIN
* Offre : ServiceBrain
* Requiert : ServiceMouvement + ServiceSonar + Gyroscope + IA
*/
class Brain :
public RequiertServiceMouvement,
public RequiertServiceSonar,
public RequiertServiceGyroscope,
public RequiertServiceIA
{

        private :
                /**
                * Pointeurs vers services requis
                */
                ServiceMouvement* serviceMouvement;
                ServiceSonar* serviceSonar;
                ServiceGyroscope* serviceGyroscope;
					 ServiceIA* serviceIA;

                /* Compteur de pas global */
                int pasCourant;

        public :

                /* Service */
                void init();

                /* ServiceBrain */
                void start();

					 /* Get pasCourent */
					 int getPasCourant();

                /* RequiertServiceMouvement */
                void bindService(ServiceMouvement * serviceMouvement);
					 ServiceMouvement* getServiceMouvement();

                /* RequiertServiceSonar */
                void bindService(ServiceSonar * serviceSonar);
					 ServiceSonar* getServiceSonar();

                /* RequiertServiceSonar */
                void bindService(ServiceGyroscope * serviceGyroscope);
					 ServiceGyroscope* getServiceGyroscope();

					 /* RequiertServiceIA */
                void bindService(ServiceIA * serviceIA);
					 ServiceIA* getServiceIA();


};

/* BRAIN_H_GUARD */
#endif
