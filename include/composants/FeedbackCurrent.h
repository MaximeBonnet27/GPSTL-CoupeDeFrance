#ifndef FEEDBACK_H_GUARD
#define FEEDBACK_H_GUARD

#include "mbed.h"
#include "ServiceFeedbackCurrent.h"

/**
 * Composant Feedback current reader
 * Offre : ServiceFeedback current
 * Requiert : /
 */

class FeedbackCurrent :
public ServiceFeedbackCurrent
{
    private :
    AnalogIn *left;
    AnalogIn *right;

    public :
    /* Service */
    void init();

    /* ServiceFeedback */
    float read_left();
    float read_right();

    inline bool isAbove(float value) {
        return read_left() >= value && read_right() >= value;
    }
};

#endif
