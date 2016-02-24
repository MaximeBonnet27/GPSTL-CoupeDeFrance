#include "Parameters.h"

int pasCourrant;

Brian::Brian(){}

void Brian::bindServiceMouvement(ServiceMouvement* service) {
  mouvement=service;
  return;
}

void Brian::init() {
  pasCourrant=0;
  return;
}

void Brian::step() {
  if (pasCourrant>=20){
    mouvement->stop();
    return;
  } else {
    mouvement->avancer(4);
    pasCourrant++;
    return;
  }
}
