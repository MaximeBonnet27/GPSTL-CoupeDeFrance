#include "Logger.h"

void Logger::error(std::string message){
        std::cout << "/e " << message << std::endl;
}
void Logger::debug(std::string message){
        std::cout << "/d " << message << std::endl;

}
void Logger::info(std::string message){
        std::cout << "/i " << message << std::endl;

}
void Logger::warning(std::string message){
        std::cout << "/w " << message << std::endl;

}

void Logger::valeur(std::string message){
        std::cout << "/p " << message << std::endl;

}
