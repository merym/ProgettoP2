#include "Modello/Interfacce/magicInterface.cpp"

class Mago: public MagicInterface{
private:	//meglio cosi o come parametro di ogni funzione? il costo in mana non cambia, secondo me meglio metterle statiche
	static int costoManaAbilita1;
	static int costoManaAbilita2;
	static int costoManaAbilita3;
	
public:
	//Mago(int health, int baseAttack, int level, int expPoint, int armor): health(50), baseAttack(20), level(1), expPoint(0), armor(10) {}

	//ogni abilità ha un parametro m che indica il mana necessario per lanciarla o è meglio metterlo come paramentro interno alla funzione?
	virtual int expelliarmus(){ //abilità1, sempre disponibile
		int dmg = baseAttack + 10*level;
		if(isThrowable(costoManaAbilita1) == true){
			setMana(costoManaAbilita1); //aggiorno il mana
			return dmg;
		} else
			return 0; //forse sarà la GUI a gestirlo mettendo in OFF il bottone
	} 

	virtual int expectoPatronum(){ //abilità2, costa 2 turni, fa danni e guarisce il mago
		int dmg = baseAttack + 18*level;
		if(isThrowable(costoManaAbilita2) == true){
			setHealthHeal(15*level); //guarisce il mago di 15*lvl
			setMana(costoManaAbilita2); 
			return dmg;
		} else
			return 0; //forse sarà la GUI a gestirlo mettendo in OFF il bottone
	}

	virtual int avadaKedavra(){	//abilità speciale, costa 3 turni, uccide in un colpo solo il nemico
		int dmg = baseAttack + 1000; //indicativo, deve oneshottare il nemico
		if(isThrowable(costoManaAbilita3) == true){
			setMana(costoManaAbilita3); 
			return dmg;
		} else
			return 0; //forse sarà la GUI a gestirlo mettendo in OFF il bottone
	}
};
int Mago::costoManaAbilita1 = 20;
int Mago::costoManaAbilita2 = 40;
int Mago::costoManaAbilita3 = 80;
