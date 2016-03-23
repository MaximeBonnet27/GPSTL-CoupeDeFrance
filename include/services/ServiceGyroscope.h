#ifndef SERVICE_GYRO_H_GUARD
#define SERVICE_GYRO_H_GUARD

#include "Service.h"

class ServiceGyroscope : public Service {
    public :
    virtual float getHeading() = 0;
    virtual bool read_gyroscope(float *gx, float *gy, float *gz) = 0;

};

class RequiertServiceGyroscope {
    public :
    	virtual void bindService(ServiceGyroscope* service) = 0;
	 	virtual ServiceGyroscope* getServiceGyroscope() = 0;
};

/* SERVICE_GYRO_H_GUARD */
#endif
