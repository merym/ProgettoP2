#include "Modello/Interfacce/dpsInterface.cpp"

//derivazione non virtual
class Soldato: public DpsInterface{
protected:
    //NB: metti valori x soldato (non per arcere)
    bool increaseLevel(const int& newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
        if(newExpPoint + getExpPoint() >= 100){
            Personaggio::increaseLevel(newExpPoint);
            increaseMaxHealth(getMaxHealth()+5*getLevel());
            increaseArmor(getArmor()+3*getLevel());
            increaseAttack(getBaseAttack()+6*getLevel());
            increaseProbCritico();
            return true;
        }
        else{
            return false;
        }
    }

  public:
    Soldato(); //i dati come: vita, armor ecc. sono inizializzati nel costruttore che utilizza per� quello della classe personaggio
    ~Soldato();
    int pugnoFurtivo(){
      return 2*getBaseAttack()*critico()+getLevel();
    }

    //IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI

    int fendente(){
      return (3*getBaseAttack()*critico()+getLevel())+3;
    }

    int coltellata(){
      return 2*getBaseAttack()*critico()+getLevel()*3;
    }
};
