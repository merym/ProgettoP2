#include "Modello/Interfacce/dpsInterface.cpp"

//derivazione non virtual
class Soldato: public DpsInterface{
  private:

  public:
    Soldato(); //i dati come: vita, armor ecc. sono inizializzati nel costruttore che utilizza per� quello della classe personaggio
    ~Soldato();
    int pugnoFurtivo(){
      return 4*critico();
    }

    //IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI

    int fendente(){
      return 6*critico();
    }

    int coltellata(){
      return 9*critico();
    }
};
