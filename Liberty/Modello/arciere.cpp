//derivazione non virtual
class Arciere: public DpsInterface{
  private:

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
