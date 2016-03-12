#ifndef SERVICE_GYRO_H_GUARD
#define SERVICE_GYRO_H_GUARD

#include "Service.h"

class ServiceGyroscope : public Service {
    public :
    virtual float angle() = 0;
};

class RequiertServiceGyroscope {
    public :
    virtual void bindService(ServiceGyroscope* service) = 0;
};

/* SERVICE_GYRO_H_GUARD */
#endif