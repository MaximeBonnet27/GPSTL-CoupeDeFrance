#ifndef SERVICE_BRAIN_H_GUARD
#define SERVICE_BRAIN_H_GUARD

#include "Service.h"

class ServiceBrain : public Service {
        public :
                virtual void start() = 0;
};

class RequiertServiceBrain {
        public :
                virtual void bindService(ServiceBrain* service) = 0;

};

/* SERVICE_BRAIN_H_GUARD */
#endif
