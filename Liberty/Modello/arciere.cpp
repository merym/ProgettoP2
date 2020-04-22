//derivazione non virtual
class Arciere: public DpsInterface{
  private:
  	
  public:
  	Arciere(); //i dati come: vita, armor ecc. sono inizializzati nel costruttore che utilizza però quello della classe personaggio
  	~Arciere();
  	int FrecciaAppuntita(){
  	  return 5*Critico();
    }
    
    //IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
    
    int FrecciaInfuocata(){
      return 8*Critico(); 
	}
	
	int FrecciaPesante(){
	  return 7*Critico();
	}
};
