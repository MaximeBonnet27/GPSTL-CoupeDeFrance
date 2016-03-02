#ifndef LOGGER_H_GUARD
#define LOGGER_H_GUARD

#include <iostream>
#include <string>

class Logger {
        public :
                static void error(std::string message);
                static void debug(std::string message);
                static void info(std::string message);
                static void warning(std::string message);

                static void valeur(std::string message);
};

/* LOGGER_H_GUARD */
#endif
