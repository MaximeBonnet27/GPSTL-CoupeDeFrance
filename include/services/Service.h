#ifndef SERVICE_H_GUARD
#define SERVICE_H_GUARD

/**
 * Classe abstraite représentant un Service
 * Contient uniquement une méthode d'initialisation, car on ne doit pas utiliser
 * les constructeurs pour initialiser les services.
 */
class Service {
        public :
                virtual void init() = 0;
};

/* SERVICE_H_GUARD */
#endif
