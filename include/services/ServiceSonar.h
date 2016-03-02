#ifndef SERVICE_SONAR_H_GUARD
#define SERVICE_SONAR_H_GUARD

class ServiceSonar : public Service {
        public :
                virtual bool aDetecteObstacle() = 0;
                virtual double distanceObstacle() = 0;
};

class RequiertServiceSonar : public RequiertService<ServiceSonar>;

/* SERVICE_SONAR_H_GUARD */
#endif SERVICE_SONAR_H_GUARD
