class MagicInterface: virtual public Personaggio{
private:
	static int maxMana;	//mana disponibile all'inizio dello scontro per ogni mago (massimo) -> usato da increaseLevel() -> aumenta col livello

	int mana = maxMana;	//mana che si aggiorna ogni volta che si lancia un'abilità; inizialmente uguale a maxMana

protected:
	//usato da increaselevel
	virtual void increaseMaxMana(){
		maxMana += 20*getLevel();
	}

	//usato da increaselevel
	virtual void increaseMaxHealth(){
		MaxHealth += 10*getLevel();	//getMaxHealth ? altrimenti come accedo al campo 
	}

	//usato da increaselevel
  	virtual void increaseArmor(){
  		armor = getArmor() + 2*getLevel();
  	} 

  	//usato da increaselevel
  	virtual void increaseAttack(){
  		baseAttack = getBaseAttack() + 8*getLevel();
  	} 

  	virtual int reducedDamageWithArmor(const int& damage) const{
  		damage -= (damage*getArmor())/100;	//danno ridotto dall'armatura in percentuale. Esempio: damage = 80 e armor = 20 -> 80 - (80*20)/100 = 80 - 20% = 64
  	}

  	void setHealth(const int& damage){ //aggiorno health dopo aver subito l'attacco
  		health = getHealth() - damage;
  	}

  	void setHealthHeal(const int& heal){ //aggiorno health dopo il lancio dell'abilità2
  		health = getHealth() + heal;
  	}

public:
	int getMaxMana() const {return maxMana;}

	int getMana() const {return mana;}

	virtual void IncreaseLevel(const int& newExpPoint){
		if(newExpPoint + getExpPoint() >= soglia){ //soglia da definire
  			SetLevel(1);
  			increaseMaxMana();
  			increaseMaxHealth();
  			increaseArmor();
  			increaseAttack();
		} else
			resetMana();
	}

	bool isThrowable(const int& m) const{ //controlla se il mago ha il mana necessario per lanciare l'abilità
  		if(mana < m)
  			return false;
  		return true;
  	}

	//aggiorna il mana dopo il lancio di un'abilità
	void setMana(const int& m){	
		mana -= m;
	}

	//subisco l'attacco, quindi aggiorno la vita col danno ridotto in base all'armor
	void ReceiveDamage(const int& damage){
		damage = reducedDamageWithArmor(damage);
		setHealth(damage);
	}

	//per ripristinare il mana alla fine di uno scontro, anche se non è aumentato di livello
	void resetMana(){
		mana = maxMana;
	}
};
int MagicInterface::maxMana = 100;

// getMaxHealth(): come facciamo ad aumentare la vita iniziale (massima) da una classe derivata se non possiamo accedere al campo privato di Personaggio()?