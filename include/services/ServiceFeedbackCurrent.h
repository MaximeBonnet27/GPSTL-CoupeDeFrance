#ifndef SERVICE_FEEDBACK_H_GUARD
#define SERVICE_FEEDBACK_H_GUARD

#include "Service.h"

class ServiceFeedbackCurrent : public Service {
    public :
    virtual float read_left() = 0;
    virtual float read_right() = 0;
    virtual bool isAbove(float value) = 0;
};

class RequiertServiceFeedbackCurrent {
    public :
    	virtual void bindService(ServiceFeedbackCurrent* service) = 0;
	 	virtual ServiceFeedbackCurrent* getFeedbackCurrentService() = 0;
};

/* SERVICE_FEEDBACK_H_GUARD */
#endif
