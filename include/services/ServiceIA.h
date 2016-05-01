#ifndef SERVICE_IA_H_GUARD
#define SERVICE_IA_H_GUARD

#include "Service.h"

class ServiceIA : public Service {
    public :
    virtual void init() = 0;
    virtual void step() = 0;
    virtual bool isFinished() = 0;

};

class RequiertServiceIA {
    public :
    	virtual void bindService(ServiceIA* service) = 0;
		virtual ServiceIA* getServiceIA() = 0;
};

/* SERVICE_GYRO_H_GUARD */
#endif
