#include "personaggio.cpp"

class MagicInterface: virtual public Personaggio{
private:
    int maxMana;	//mana disponibile all'inizio dello scontro per ogni mago (massimo) -> usato da increaseLevel() -> aumenta col livello

    int mana;	//mana che si aggiorna ogni volta che si lancia un'abilità; inizialmente uguale a maxMana

protected:
	//usato da increaselevel
    virtual void increaseMaxMana(int addVal){
        maxMana += addVal;
	}

    /*
    //usato da increaselevel
	virtual void increaseMaxHealth(){
        maxHealth = getMaxHealth() + 10*getLevel();	//getMaxHealth ? altrimenti come accedo al campo
	}

	//usato da increaselevel
  	virtual void increaseArmor(){
  		armor = getArmor() + 2*getLevel();
  	} 

  	//usato da increaselevel
  	virtual void increaseAttack(){
  		baseAttack = getBaseAttack() + 8*getLevel();
  	} 
    */

public:
    MagicInterface(int m): maxMana(m), mana(m) {}

	int getMaxMana() const {return maxMana;}

	int getMana() const {return mana;}

	bool isThrowable(const int& m) const{ //controlla se il mago ha il mana necessario per lanciare l'abilità
  		if(mana < m)
  			return false;
  		return true;
  	}

	//aggiorna il mana dopo il lancio di un'abilità
	void setMana(const int& m){	
		mana -= m;
	}

	//per ripristinare il mana alla fine di uno scontro, anche se non è aumentato di livello
	void resetMana(){
		mana = maxMana;
	}
};
//int MagicInterface::maxMana = 100;
