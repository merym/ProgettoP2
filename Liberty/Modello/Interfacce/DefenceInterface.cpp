class DefenceInterface: virtual public personaggio{
  private:
  	int Turni;
  	int MaxArmor;
  protected:
  	virtual void IncrementaTurni(){
  	  Turni=3;
	}
	//decrementaturni lo invoca ogni abilità del personaggio della classe defenceinterface
	//Turni viene decrementato solo quando il personaggio che ha utlizzato l'abilità BuffArmor è in uso dall'utente
	void DecrementaTurni(){ 
	  if(Turni!=0){
	    Turni--;
	    SetMaxArmor(GetArmor());
      }
	}
  	void SetMaxArmor(const int& Arm){
  	  MaxArmor=Arm;
	}
  public:
  	//incrementa l'armatura, se non è disponibile l'abilità (Turni !=0) restituisce false, altrimenti true
  	virtual bool BuffArmor(){
  	  if(Turni!=0)
  	    return false;
  	  SetMaxArmor(GetArmor()+3*GetLevel());
  	  return true;
    }
  	
};
