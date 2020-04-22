#include <iostream>

class Personaggio{
  private:
    unsigned int maxHealth;
    unsigned int health;
    int baseAttack;
    int level;
    int expPoint;
    int armor;

    //proposta da healInterf-> aggiungere un campo bool Dead x controllare stato, (hp==0? true : false)
    bool dead;
  protected:
    virtual void increaseMaxhealth(); //usato da increaselevel, RESETTA ANCHE HEALTH AL MAX VALUE
    virtual void increaseArmor(); //usato da increaselevel
    virtual void increaseAttack(); //usato da increaselevel
    void setLevel(const int& newLevel){
  		level += newLevel;
  	} //usato da increaselevel (serve ad accedere al campo privato)

    void setHealth(const int& damage){//proposta da healInterf:(int+)= guarigione; (int-)=colpo subito; 0=Dead==true
        health+=damage;
        if(health==0){
            kill();
        }
    }

    int reducedDamageWithArmor(const int& damage) const{ //restituisce il danno ridotto dall'armatura (in defence interface usa maxarmor, invece che armor)
        return damage - (damage*armor)/100;
    }

    //proposta da healIntef
    //per riportare in vita un personaggio, va chiamato DURANTE UNA BATTAGLIA
    void resurrect(){
        dead=false;
    }
    //per uccidere un personaggio dopo setHealth
    void kill(){
        dead=true;
    }

  public:
  	Personaggio();
  	virtual ~Personaggio()=0;
    int getHealth() const{return health;}
    int getMaxHealth() const{return maxHealth;}
    int getBaseAttack() const{return baseAttack;}
    int getLevel() const{return level;}
    int getExpPoint() const{return expPoint;}
    int getArmor() const{return armor;}

    //proposta da healInterf->per modificare i campi specifici delle interfaccie deve essere virtuale! && potrebbe ritornare se è avvenuto o no un cambio lvl wt a BOOL
    virtual bool increaseLevel(const int& newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
        if(newExpPoint + getExpPoint() >= soglia){
            setLevel(1);
            increaseAttack();
            increaseArmor();
            increaseMaxhealth();
        }
    }

    void receiveDamage(const int& damage){//utilizza SetHealth e ReducedDamageWithArmor -> varia in base al personaggio; per diminuire HP (hp=hp-damage) tramite setHP
        damage= (-1)*reducedDamageWithArmor(damage);
        setHealth(damage);
    }

    //proposte da healInterf
    bool getDeathState()const {return dead;}//in lettura, per il controller

    //gain=hp guarita, divineIntervention=is a REZ or NOT
    void receiveHealing(const int & gain, bool divineIntervention=false){//chiamato da controller (O da contenitore?) per aumentare Health (hp= hp+gain) tramite setHP
        if(dead==divineIntervention){//valori concordanti, guarigione NORM o REZ
            setHealth(gain);
            if(dead)
                resurrect();
        }
        else{//valori discordanti
            //ERRORE: non è possibile normale guarigione su cadavere || riportare in vita un personaggio già vivo
        }
    }

};
