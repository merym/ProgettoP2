#include <iostream>
#include <QString>

class Personaggio{
  private:
    unsigned int maxHealth;
    int health;
    unsigned int baseAttack;
    unsigned int level;
    unsigned int expPoint;
    unsigned int armor;
    //proposta da healInterf-> aggiungere un campo bool Dead x controllare stato, (hp==0? true : false)
    bool dead;
    const QString tipoPersonaggio;// dovrebbe essere static? idk
    const QString nome;
    const unsigned int prezzo;
    
  protected:
    void increaseMaxHealth(unsigned int addVal){ maxHealth+= addVal; health=static_cast<int>(maxHealth);} //usato da increaselevel, RESETTA ANCHE HEALTH AL MAX VALUE
    void increaseArmor(unsigned int addVal){ armor+= addVal;} //usato da increaselevel
    void increaseAttack(unsigned int addVal){ baseAttack+= addVal;} //usato da increaselevel
    void setLevel(unsigned int newLevel){
  		level += newLevel;
  	} //usato da increaselevel (serve ad accedere al campo privato)

    void setHealth(int damage){//proposta da healInterf:(int+)= guarigione; (int-)=colpo subito; 0=Dead==true
        health=health + damage;
        if(health<=0){
            kill();
            health=0;
        }
    }

    virtual unsigned int reducedDamageWithArmor(unsigned int damage) const{ //restituisce il danno ridotto dall'armatura (in defence interface usa maxarmor, invece che armor)
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
    Personaggio() {}
    Personaggio(unsigned int mh, 
                unsigned int ba, 
                unsigned int lv, 
                unsigned int a,
                QString t, 
                QString n, 
                unsigned int p): 
                   maxHealth(mh), 
                   health(static_cast<int>(mh)), 
                   baseAttack(ba),
                   level(lv),
                   expPoint(0),
                   armor(a),
                   dead(true),
                   tipoPersonaggio(t),
                   nome(n),
                   prezzo(p){}
                   
                 
  	virtual ~Personaggio()=0;
    QString getTipoPersonaggio()const{ return tipoPersonaggio;}
    QString getNome()const{ return nome;}
    unsigned int getPrezzo() const{return prezzo;}
    
    int getHealth() const{return health;}
    unsigned int getMaxHealth() const{return maxHealth;}
    unsigned int getBaseAttack() const{return baseAttack;}
    unsigned int getLevel() const{return level;}
    unsigned int getExpPoint() const{return expPoint;}
    unsigned int getArmor() const{return armor;}

    //proposta da healInterf->per modificare i campi specifici delle interfaccie deve essere virtuale! && potrebbe ritornare se è avvenuto o no un cambio lvl wt a BOOL
    virtual bool increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
        if(newExpPoint + getExpPoint() >= 100){
            setLevel(1);
            return true;
        }
        return false;
        
    }

    void receiveDamage(unsigned int damage){//utilizza SetHealth e ReducedDamageWithArmor -> varia in base al personaggio; per diminuire HP (hp=hp-damage) tramite setHP
        int dmg= (-1)*static_cast<int>(reducedDamageWithArmor(damage));
        setHealth(dmg);
    }

    //proposte da healInterf
    bool getDeathState()const {return dead;}//in lettura, per il controller

    //gain=hp guarita, divineIntervention=is a REZ or NOT
    void receiveHealing(unsigned int gain, bool divineIntervention=false){//chiamato da controller (O da contenitore?) per aumentare Health (hp= hp+gain) tramite setHP
        if(dead==divineIntervention){//valori concordanti, guarigione NORM o REZ
            setHealth(static_cast<int>(gain));
            if(dead)
                resurrect();
        }
        else{//valori discordanti
            //ERRORE: non è possibile normale guarigione su cadavere || riportare in vita un personaggio già vivo
        }
    }

};
