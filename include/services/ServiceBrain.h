#ifndef SERVICE_BRAIN_H_GUARD
#define SERVICE_BRAIN_H_GUARD

class ServiceBrain : public Service {
        public :
                virtual void start() = 0;
};

class RequiertServiceBrain : RequiertService<ServiceBrain>;

/* SERVICE_BRAIN_H_GUARD */
#endif
