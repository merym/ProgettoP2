//derivazione non virtual
class Soldato: public DpsInterface{
  private:
  	
  public:
  	Soldato(); //i dati come: vita, armor ecc. sono inizializzati nel costruttore che utilizza però quello della classe personaggio
  	~Soldato();
  	int PugnoFurtivo(){
  	  return 4*Critico();
    }
    
    //IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
    
    int Fendente(){
      return 6*Critico(); 
	}
	
	int Coltellata(){
	  return 9*Critico();
	}
};
