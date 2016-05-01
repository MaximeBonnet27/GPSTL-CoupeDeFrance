#ifndef STAGE1_H_GUARD
#define STAGE1_H_GUARD

#include "ServiceMouvement.h"
#include "ServiceIA.h"
#include "State.h"
#include "AbstractIA.h"

#define UN_METRE (15080)

#define DUREE_POUSSEE_MAX 2000

#define ETAT_0_ATTENTE 0
#define ETAT_1_POUSSER_CUBES 1
#define ETAT_2_RECULER 2
#define ETAT_3_DROITE_90 3
#define ETAT_4_POUSSER_PORTE 4
#define ETAT_5_RECULER_UN_PEU 5
#define ETAT_6_DROITE_90 6
#define ETAT_7_AVANCER 7
#define ETAT_8_GAUCHE_90 8
#define ETAT_9_POUSSER_PORTE 9
#define ETAT_10_RECULER 10
#define ETAT_11_GAUCHE_90 11
#define ETAT_12_REPOSITION 12

class Stage1 : public AbstractIA {
    private :

        int etatCourant;
        bool etatCourantInitialise;
        int dureeEtat;

        // Variables poussee :
        bool commenceAPousser;
        int dureePoussee;

        void reset();

    public  :
        void init();
        void step();
        bool isFinished();

        Stage1(Brain* brain);
};

#endif
