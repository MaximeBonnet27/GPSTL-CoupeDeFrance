#ifndef LOGGER_H_GUARD
#define LOGGER_H_GUARD

#include <iostream>
#include <string>

/**
 * Classe utilitaire qui permet d'utiliser le logger écrit par l'équipe
 * R&D (rajoute les en-têtes nécessaires pour qu'ils soient bien pris en compte)
 * On suppose que les messages passés en paramètre ne contiennent *pas* de \n
 * à la fin !
 */
class Logger {
        public :
                static void error(std::string message);
                static void debug(std::string message);
                static void info(std::string message);
                static void warning(std::string message);

                /** Permet de logger une valeur dans un fichier différent
                 * voir si utile
                 */
                static void valeur(std::string message);
};

/* LOGGER_H_GUARD */
#endif
