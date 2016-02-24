//---SERVICES---//
class ServiceMouvement {
  public:
    virtual void avancer(int puissance)=0;
    virtual void stop()=0;
};

class ServiceRequisMouvement {
  public:
    virtual void bindServiceMouvement(ServiceMouvement* service)=0;
};

class ServiceInitialisation {
  public:
    virtual void init()=0;
};
class ServiceRequisInitialisation {
  public:
    virtual void bindServiceInitialisation(ServiceInitialisation* service)=0;
};

class ServiceStep {
  public:
    virtual void step()=0;
};
class ServiceRequisStep {
  public:
    virtual void bindServiceStep(ServiceStep* service)=0;
};



//---COMPOSANTS---//
class Moteur: public ServiceMouvement {
  public:
    Moteur();
    void avancer(int puissance);
    void stop();
};

class Brian: public ServiceRequisMouvement,
             public ServiceInitialisation,
             public ServiceStep {
  private:
    ServiceMouvement* mouvement;
  public:
    Brian();
    void init();
    void step();
    void bindServiceMouvement(ServiceMouvement* service);
};
