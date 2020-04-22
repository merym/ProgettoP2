#include "Modello/Interfacce/magicInterface.cpp"

class Mago: public MagicInterface{
private:
    static const int costoManaAbilita1;
    static const int costoManaAbilita2;
    static const int costoManaAbilita3;

protected:
    virtual void IncreaseLevel(const int& newExpPoint){
		if(newExpPoint + getExpPoint() >= 100){ //soglia da definire
            Personaggio::increaseLevel(newExpPoint);
  			increaseMaxMana(20*getLevel());
		} else
			resetMana();
	}
    
public:
	//Mago(int health, int baseAttack, int level, int expPoint, int armor): health(50), baseAttack(20), level(1), expPoint(0), armor(10) {}
    ~Mago();
	//ogni abilità ha un parametro m che indica il mana necessario per lanciarla o è meglio metterlo come paramentro interno alla funzione?
	virtual int expelliarmus(){ //abilità1, sempre disponibile
		int dmg = getBaseAttack() + 10*getLevel();
		if(isThrowable(costoManaAbilita1) == true){
			setMana(costoManaAbilita1); //aggiorno il mana
			return dmg;
		} else
            return 0;
	} 

	virtual int expectoPatronum(){ //abilità2, costa 2 turni, fa danni e guarisce il mago
		int dmg = getBaseAttack() + 18*getLevel();
		if(isThrowable(costoManaAbilita2) == true){
            receiveHealing(5*getLevel(), false); //guarisce il mago
			setMana(costoManaAbilita2); 
			return dmg;
		} else
            return 0;
	}

	virtual int avadaKedavra(){	//abilità speciale, costa 3 turni, uccide in un colpo solo il nemico
		int dmg = getBaseAttack() + 1000; //indicativo, deve oneshottare il nemico
		if(isThrowable(costoManaAbilita3) == true){
			setMana(costoManaAbilita3); 
			return dmg;
		} else
            return 0;
	}
};
const int Mago::costoManaAbilita1 = 20;
const int Mago::costoManaAbilita2 = 40;
const int Mago::costoManaAbilita3 = 80;
