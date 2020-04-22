#include "Modello/Interfacce/magicInterface.cpp"

class Mago: public MagicInterface{
private:
    static const unsigned int costoManaAbilita1;
    static const unsigned int costoManaAbilita2;
    static const unsigned int costoManaAbilita3;

protected:
    //controlla
    bool increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
      if(newExpPoint + getExpPoint() >= 100){
        Personaggio::increaseLevel(newExpPoint);
        increaseMaxHealth(getMaxHealth()+5*getLevel());
        increaseArmor(getArmor()+3*getLevel());
        increaseAttack(getBaseAttack()+6*getLevel());
        increaseMaxMana(getMana()+15*getLevel());
        return true;
      }
      else {
          resetMana();
          return false;
      }
    }
    
public:
	//Mago(int health, int baseAttack, int level, int expPoint, int armor): health(50), baseAttack(20), level(1), expPoint(0), armor(10) {}
    ~Mago();
	//ogni abilità ha un parametro m che indica il mana necessario per lanciarla o è meglio metterlo come paramentro interno alla funzione?
    virtual unsigned int expelliarmus(){ //abilità1, sempre disponibile
        unsigned int dmg = getBaseAttack() + 10*getLevel();
		if(isThrowable(costoManaAbilita1) == true){
			setMana(costoManaAbilita1); //aggiorno il mana
			return dmg;
		} else
            return 0;
	} 

    virtual unsigned int expectoPatronum(){ //abilità2, costa 2 turni, fa danni e guarisce il mago
        unsigned int dmg = getBaseAttack() + 18*getLevel();
		if(isThrowable(costoManaAbilita2) == true){
            receiveHealing(5*getLevel(), false); //guarisce il mago
			setMana(costoManaAbilita2); 
			return dmg;
		} else
            return 0;
	}

    virtual unsigned int avadaKedavra(){	//abilità speciale, costa 3 turni, uccide in un colpo solo il nemico
        unsigned int dmg = getBaseAttack() + 1000; //indicativo, deve oneshottare il nemico
		if(isThrowable(costoManaAbilita3) == true){
			setMana(costoManaAbilita3); 
			return dmg;
		} else
            return 0;
	}
};
const unsigned int Mago::costoManaAbilita1 = 20;
const unsigned int Mago::costoManaAbilita2 = 40;
const unsigned int Mago::costoManaAbilita3 = 80;
