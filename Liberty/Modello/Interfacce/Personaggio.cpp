#include <iostream>

class Personaggio{
  private:
    unsigned int MaxHealth;
    unsigned int Health;
  	int BaseAttack;
  	int Level;
  	int Exppoint;
  	int Armor;

    //proposta da healInterf-> aggiungere un campo bool Dead x controllare stato, (hp==0? true : false)
    bool Dead;
  protected:
    virtual void IncreaseMaxhealth(); //usato da increaselevel, RESETTA ANCHE HEALTH AL MAX VALUE
    virtual void IncreaseArmor(); //usato da increaselevel
  	virtual void IncreaseAttack(); //usato da increaselevel
  	void SetLevel(const int& newLevel){
  		level += newLevel;
  	} //usato da increaselevel (serve ad accedere al campo privato)

    void SetHealth(const int& Damage){//proposta da healInterf:(int+)= guarigione; (int-)=colpo subito; 0=Dead==true
        Health+=Damage;
        if(Health==0){
            kill();
        }
    }

    int ReducedDamageWithArmor(const int& Damage) const{ //restituisce il danno ridotto dall'armatura (in defence interface usa maxarmor, invece che armor)
        return Damage- (Damage*Armor)/100;
    }

    //proposta da healIntef
    //per riportare in vita un personaggio, va chiamato DURANTE UNA BATTAGLIA
    void resurrect(){
        Dead=false;
    }
    //per uccidere un personaggio dopo setHealth
    void kill(){
        Dead=true;
    }

  public:
  	Personaggio();
  	virtual ~Personaggio()=0;
    int GetHealth() const{return Health;}
    int GetMaxHealth() const{return MaxHealth;}
    int GetBaseAttack() const{return BaseAttack;}
    int GetLevel() const{return Level;}
    int GetExppoint() const{return Exppoint;}
    int GetArmor() const{return Armor;}

    //proposta da healInterf->per modificare i campi specifici delle interfaccie deve essere virtuale! && potrebbe ritornare se è avvenuto o no un cambio lvl wt a BOOL
    virtual bool IncreaseLevel(const int& newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
        if(newExpPoint + GetExppoint() >= soglia){
            SetLevel(1);
            IncreaseAttack();
            IncreaseArmor();
            IncreaseMaxhealth();
        }
    }

    void ReceiveDamage(const int& Damage){//utilizza SetHealth e ReducedDamageWithArmor -> varia in base al personaggio; per diminuire HP (hp=hp-damage) tramite setHP
        Damage= (-1)*ReducedDamageWithArmor(Damage);
        SetHealth(Damage);
    }

    //proposte da healInterf
    bool getDeathState()const {return Dead;}//in lettura, per il controller

    //gain=hp guarita, divineIntervention=is a REZ or NOT
    void ReceiveHealing(const int & Gain, bool DivineIntervention=false){//chiamato da controller (O da contenitore?) per aumentare Health (hp= hp+gain) tramite setHP
        if(Dead==DivineIntevention){//valori concordanti, guarigione NORM o REZ
            SetHealth(gain);
            if(Dead)
                resurrect();
        }
        else{//valori discordanti
            //ERRORE: non è possibile normale guarigione su cadavere || riportare in vita un personaggio già vivo
        }
    }

};
