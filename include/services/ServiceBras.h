#ifndef SERVICE_BRAS_H_GUARD
#define SERVICE_BRAS_H_GUARD

#include "Service.h"

class ServiceBras : public Service {
    public :
    	virtual void ouvrir(int pourcentage) = 0;
		virtual int getOuverture() = 0;
};

class RequiertServiceBras {
    public :
    	virtual void bindService(ServiceBras* service) = 0;
	 	virtual ServiceBras* getServiceBras() = 0;
};

/* SERVICE_BRAS_H_GUARD */
#endif
