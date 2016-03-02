#ifndef SERVICE_MOUVEMENT_H_GUARD
#define SERVICE_MOUVEMENT_H_GUARD

/**
 * Service Offert
 */

class ServiceMouvement : public Service {
        public :
        /*
         * Fonctionnalités "natives"
         */
                virtual void avancer(int puissance) = 0;
                virtual void reculer(int puissance) = 0;
                virtual void tourner(int puissance, double angle) = 0;
                virtual void stopper() = 0;
        /*
         * Commodités
         */
                virtual void faireDemiTour(int puissance) = 0;
                virtual void tournerAngleDroitGauche(int puissance) = 0;
                virtual void tournerAngleDroitDroite(int puissance) = 0;
};

/**
 * Service Binding
 */

 class RequiertServiceMouvement : public RequiertService<ServiceMouvement>;

/* SERVICE_MOUVEMENT_H_GUARD */
#endif
