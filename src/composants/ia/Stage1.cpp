#include "Stage1.h"
#include "Brain.h"
#include "Logger.h"

Stage1::Stage1(Brain* brain) : AbstractIA(brain) {
        this->brain = brain;
}

void Stage1::reset(){
        etatCourantInitialise = false;
        brain->getServiceMouvement()->stopper(1.0);
        finiComportementSimple = false;

        commenceAPousser = false;
        dureePoussee = 0;
        dureeEtat = 0;

        wait(0.3);
}

void Stage1::init(){
        etatCourant = ETAT_0_ATTENTE;
        reset();
}

void Stage1::step(){
        std::ostringstream ss;
        ss << brain->getServiceMouvement()->getIntensiteMoteurDroite();
        Logger::info("Intensite : " + std::string(ss.str()));

        dureeEtat++;
        switch (etatCourant) {
                case ETAT_0_ATTENTE :
                        Logger::info("Etat 0");
                        wait(3);
                        etatCourant = ETAT_1_POUSSER_CUBES;
                break;
                case ETAT_1_POUSSER_CUBES :
                        Logger::info("Etat 1");
                        /*
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->avancer(1.0);
                        }

                        commenceAPousser = commenceAPousser ||
                                ((dureeEtat > STEP_AVANT_CHECK_COLLISION)
                                        && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > 0.5
                                                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > 0.5));


                        if(commenceAPousser){
                                dureePoussee++;
                                if(dureePoussee == DUREE_POUSSEE_MAX){
                                        etatCourant = ETAT_2_RECULER;
                                        reset();
                                }
                        }
                        */

                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        avancer(1.0, UN_METRE);
                        if(finiComportementSimple){
                                etatCourant = ETAT_2_RECULER;
                                reset();
                        }



                        /*if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->avancer(1.0);
                        }
                        */
                        /*
                        if(aDetecteObstacleDerriere()){
                                etatCourant = ETAT_2_RECULER;
                                reset();
                        }
                        */


                break;
                case ETAT_2_RECULER :
                        Logger::info("Etat 2");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        reculer(1.0, UN_METRE / 2);
                        if(finiComportementSimple){
                                etatCourant = ETAT_3_DROITE_90;
                                reset();
                        }
                break;
                case ETAT_3_DROITE_90 :
                        Logger::info("Etat 3");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        tournerAngleDroitDroite(0.8);
                        if(finiComportementSimple){
                                etatCourant = ETAT_4_POUSSER_PORTE;
                                reset();
                        }
                break;
                case ETAT_4_POUSSER_PORTE :
                        Logger::info("Etat 4");
                        /*
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->avancer(1.0);
                        }

                        commenceAPousser = commenceAPousser ||
                                ((dureeEtat > STEP_AVANT_CHECK_COLLISION)
                                        && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > SEUIL_COLLISION_AVANT
                                                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > SEUIL_COLLISION_AVANT));

                        if(commenceAPousser){
                                dureePoussee++;
                                if(dureePoussee == DUREE_POUSSEE_MAX){
                                        etatCourant = ETAT_5_RECULER_UN_PEU;
                                        reset();
                                }
                        }
                        */
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        avancer(1.0, UN_METRE);
                        if(finiComportementSimple){
                                etatCourant = ETAT_5_RECULER_UN_PEU;
                                reset();
                        }
                break;
                case ETAT_5_RECULER_UN_PEU :
                        Logger::info("Etat 5");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        reculer(1.0, UN_METRE / 4);
                        if(finiComportementSimple){
                                etatCourant = ETAT_6_DROITE_90;
                                reset();
                        }
                break;
                case ETAT_6_DROITE_90 :
                        Logger::info("Etat 6");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        tournerAngleDroitDroite(0.8);
                        if(finiComportementSimple){
                                etatCourant = ETAT_7_AVANCER;
                                reset();
                        }
                break;
                case ETAT_7_AVANCER :
                        Logger::info("Etat 7");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        avancer(1.0, UN_METRE / 4);
                        if(finiComportementSimple){
                                etatCourant = ETAT_8_GAUCHE_90;
                                reset();
                        }
                break;
                case ETAT_8_GAUCHE_90 :
                        Logger::info("Etat 8");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        tournerAngleDroitGauche(0.8);
                        if(finiComportementSimple){
                                etatCourant = ETAT_9_POUSSER_PORTE;
                                reset();
                        }
                break;
                case ETAT_9_POUSSER_PORTE :
                        Logger::info("Etat 9");
                        /*
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->avancer(1.0);
                        }

                        commenceAPousser = commenceAPousser ||
                                ((dureeEtat > STEP_AVANT_CHECK_COLLISION)
                                        && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > SEUIL_COLLISION_AVANT
                                                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > SEUIL_COLLISION_AVANT));


                        if(commenceAPousser){
                                dureePoussee++;
                                if(dureePoussee == DUREE_POUSSEE_MAX){
                                        etatCourant = ETAT_10_RECULER;
                                        reset();
                                }
                        }
                        */
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        avancer(1.0, UN_METRE / 4);
                        if(finiComportementSimple){
                                etatCourant = ETAT_10_RECULER;
                                reset();
                        }
                break;
                case ETAT_10_RECULER :
                        Logger::info("Etat 10");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        reculer(1.0, UN_METRE);
                        if(finiComportementSimple){
                                etatCourant = ETAT_11_GAUCHE_90;
                                reset();
                        }
                break;
                case ETAT_11_GAUCHE_90 :
                        Logger::info("Etat 11");
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        tournerAngleDroitGauche(0.8);
                        if(finiComportementSimple){
                                etatCourant = ETAT_12_REPOSITION;
                                reset();
                        }
                break;
                case ETAT_12_REPOSITION :
                        Logger::info("Etat 12");
                        /*
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->reculer(1.0);
                        }

                        commenceAPousser = commenceAPousser ||
                                ((dureeEtat > STEP_AVANT_CHECK_COLLISION)
                                        && (brain->getServiceMouvement()->getIntensiteMoteurDroite() > 0.5
                                                || brain->getServiceMouvement()->getIntensiteMoteurGauche() > 0.5));



                        if(commenceAPousser){
                                dureePoussee++;
                                if(dureePoussee == DUREE_POUSSEE_MAX){
                                        etatCourant = ETAT_STOP;
                                        reset();
                                }
                        }
                        */
                        /*
                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                                brain->getServiceMouvement()->reculer(1.0);
                        }
                        if(aDetecteObstacleDerriere()){
                                etatCourant = ETAT_STOP;
                                reset();
                        }
                        */

                        if(!etatCourantInitialise){
                                etatCourantInitialise = true;
                        }
                        reculer(1.0, UN_METRE/4);
                        if(finiComportementSimple){
                                etatCourant = ETAT_STOP;
                                reset();
                        }
                        

                break;

        }
}

bool Stage1::isFinished(){
        return (etatCourant == ETAT_STOP);
}
