#include "ServiceMouvement.h"
#include "Logger.h"

class ServiceMouvementBouchon : public ServiceMouvement {
                void avancer(int puissance);
                void reculer(int puissance);
                void tourner(int puissance, double angle);
                void stopper();

                void faireDemiTour(int puissance);
                void tournerAngleDroitGauche(int puissance);
                void tournerAngleDroitDroite(int puissance);
};
