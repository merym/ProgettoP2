#include "Modello/Interfacce/dpsInterface.cpp"

//derivazione non virtual
class Arciere: public DpsInterface{
protected:
    bool increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
      if(newExpPoint + getExpPoint() >= 100){
        Personaggio::increaseLevel(newExpPoint);
        increaseMaxHealth(getMaxHealth()+5*getLevel());
        increaseArmor(getArmor()+3*getLevel());
        increaseAttack(getBaseAttack()+6*getLevel());
        increaseProbCritico();
        return true;
      }
      else {
          return false;
      }
    }

  public:
    Arciere(); //i dati come: vita, armor ecc. sono inizializzati nel costruttore che utilizza per� quello della classe personaggio
    ~Arciere();
    int frecciaAppuntita(){
      return 2*getBaseAttack()*critico()+getLevel();
    }

    //IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI

    int frecciaInfuocata(){
      return 3*getBaseAttack()*critico()+getLevel();
    }

    int frecciaPesante(){
      return 2*getBaseAttack()*critico()+getLevel()*2;
    }
};
