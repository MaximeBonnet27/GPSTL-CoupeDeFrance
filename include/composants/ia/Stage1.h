#ifndef STAGE1_H_GUARD
#define STAGE1_H_GUARD

#include "ServiceMouvement.h"
#include "ServiceIA.h"
#include "State.h"

class Brain;

class Stage1 :
public ServiceIA
{
    private :
        int currentState;
        int currentTransition;
        int debState;
        int nbPasAvancer1;
        int nbPasReculer1;
        Brain* brain;

    public  :
        void init();
        void step();
        bool isFinished();

        Stage1(Brain* brain);
};

#endif
