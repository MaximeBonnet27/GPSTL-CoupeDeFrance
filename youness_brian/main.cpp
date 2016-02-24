#include "mbed.h"
#include "Parameters.h"

int main() {
  //---INSTANCIATIONS---//
  ServiceMouvement* moteur=new Moteur();
  Brian* brian=new Brian();

  //---BINDING---//
  brian->bindServiceMouvement(moteur);

  //---CORPS PRINCIPAL---//
  brian->init();
  wait(1);
  while(1){
    brian->step();
    wait(0.1);
  }
}
