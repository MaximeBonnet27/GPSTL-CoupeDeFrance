#ifndef SERVICE_SONAR_H_GUARD
#define SERVICE_SONAR_H_GUARD

#include "Service.h"

class ServiceSonar : public Service {
        public :
                virtual bool aDetecteObstacle() = 0;
                virtual double distanceObstacle() = 0;
};

class RequiertServiceSonar {
        public :
                virtual void bindService(ServiceSonar* serviceSonar) = 0;
					 virtual ServiceSonar* getServiceSonar() = 0;
};

/* SERVICE_SONAR_H_GUARD */
#endif
