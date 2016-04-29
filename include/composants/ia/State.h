#ifndef STATE_H_GUARD
#define STATE_H_GUARD

// STATES
#define ETAT_NULL               0
#define ETAT_AVANCER            1L << 0
#define ETAT_RECULER            1L << 1
#define ETAT_TOURNER_DROITE     1L << 2
#define ETAT_TOURNER_GAUCHE     1L << 3
#define ETAT_COLLISION          1L << 4
#define ETAT_STOP               1L << 5

// TRANSITIONS
#define TRANSITION_AVANCER      1L << 10
#define TRANSITION_RECULER      1L << 11
#define TRANSITION_DROITE       1L << 12
#define TRANSITION_GAUCHE       1L << 13
#define TRANSITION_COLLISION    1L << 14
#define TRANSITION_STOP         1L << 15

#endif
