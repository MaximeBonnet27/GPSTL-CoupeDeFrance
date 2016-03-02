#ifndef REQUIERT_SERVICE_H_GUARD
#define REQUIERT_SERVICE_H_GUARD

/* T extends Service */
template <class T>
class RequiertService {
        public :
                virtual void bindService(T service) = 0;
};

/*  REQUIERT_SERVICE_H_GUARD */
#endif
