#ifndef BRAIN_H_GUARD
#define BRAIN_H_GUARD

#include <cstdlib>
#include <ctime>
#include <vector>

#include "mbed.h"

#include "ServiceMouvement.h"
#include "ServiceSonar.h"
#include "ServiceGyroscope.h"
#include "ServiceFeedbackCurrent.h"
#include "Logger.h"
#include "ServiceBras.h"
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
public RequiertServiceIA,
public RequiertServiceBras,
public RequiertServiceFeedbackCurrent
{

        private :
                /**
                * Pointeurs vers services requis
                */
                ServiceMouvement* serviceMouvement;
                std::vector<ServiceSonar*> servicesSonar;
                ServiceGyroscope* serviceGyroscope;
                ServiceFeedbackCurrent* feedbackCurrentService;
	            ServiceBras* serviceBras;
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

					 /* RequiertServiceBras */
                void bindService(ServiceBras * serviceBras);
					 ServiceBras* getServiceBras();

                std::vector<ServiceSonar*> getServicesSonar();

                /* RequiertServiceFeedbackCurrent */
                void bindService(ServiceFeedbackCurrent * feedbackCurrentReader);
                ServiceFeedbackCurrent* getFeedbackCurrentService();
};

/* BRAIN_H_GUARD */
#endif
