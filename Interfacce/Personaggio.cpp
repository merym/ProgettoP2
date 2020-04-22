#include <iostream>

class Personaggio{
  private:
  	static int MaxHealth;
  	int Health;
  	int BaseAttack;
  	int Level;
  	int Exppoint;
  	int Armor;

        //proposta da healInterf-> aggiungere un campo bool Dead x controllare stato, (hp==0? true : false)
        bool Dead;
  protected:
  	virtual void IncreaseMaxhealth(); //usato da increaselevel
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
  	virtual int ReducedDamageWithArmor(const int& Damage) const; //restituisce il danno ridotto dall'armatura (in defence interface usa maxarmor, invece che armor)

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
	int GetHealth() const;
        int GetBaseAttack() const;
  	int GetLevel() const;
  	int GetExppoint() const;
  	int GetArmor() const;

        //proposta da healInterf->per modificare i campi specifici delle interfaccie deve essere virtuale! && potrebbe ritornare se è avvenuto o no un cambio lvl wt a BOOL
        virtual bool IncreaseLevel(const int& newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
  		if(newExpPoint + GetExppoint() >= soglia)
  			SetLevel(1);
  	}
        void ReceiveDamage(const int& Damage); //utilizza SetHealth e ReducedDamageWithArmor -> varia in base al personaggio; per diminuire HP (hp=hp-damage) tramite setHP

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
int Personaggio::MaxHealth = x;
