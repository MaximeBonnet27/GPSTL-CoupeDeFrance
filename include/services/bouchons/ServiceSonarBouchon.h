#ifndef SERVICE_SONAR_BOUCHON_H_GUARD
#define SERVICE_SONAR_BOUCHON_H_GUARD

class ServiceSonarBouchon : public ServiceSonar {
        public :
                bool aDetecteObstacle();
                double distanceObstacle();
};

/* SERVICE_SONAR_BOUCHON_H_GUARD */
#endif
