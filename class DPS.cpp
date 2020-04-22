#include <cstdlib> //per rand()
#include <ctime> //per time()

class DPS: virtual public personaggio{
  private:
  	//ProbCritico diminuisce all'aumentare del livello del personaggio --> aumenta la probabilità di effettuare un colpo critico
  	//se all'inizio è 5, la prob. di ottenere un critico è 1/5, diminuendolo aumenta la probabilità
  	int ProbCritico;
  protected:
  	virtual void IncreaseMaxhealth(){
  		MaxHealth=MaxHealth+5*GetLevel();
	}
  	virtual void IncreaseArmor(){
  		Armor=Armor+3*GetLevel();
	  }
  	virtual void IncreaseAttack(){
  		BaseAttack=BaseAttack+6*GetLevel();
	}
	void IncreaseLevel(const int& newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
  	  if(newExpPoint + GetExppoint() >= soglia){
  		SetLevel(1);
  		IncreaseMaxHealth();
  		IncreaseArmor();
  		IncreaseAttack();
  		IncreaseProbCritico();
  	  }	
  	}
  	//il metodo per aumentare la probabilità si chiama INCREASE anche se di fatto decrementa il parametro per farlo.
  	void IncreaseProbCritico(){
  	  //Check (utile?)
	  if(ProbCritico>2)
		ProbCritico--;
	}
  	int Critico() const{
  	  //la prossima riga serve per i numeri random
  	  srand(time(NULL));
  	  //rand()%ProbCritico genera un numero casuale [0,ProbCritico-1], se esce 0 (probabilità=1/ProbCritico) si ottiene un critico
  	  //esempio: se ProbCritico è 5, si genera un numero [0,4]
  	  if((rand()%ProbCritico)==0)
  	    return 3+GetLevel(); //viene restituito un intero che sarà usato per moltiplicare il danno fatto
  	  else
  	    return 1; //se non esce 0, non si ottiene un critico; quindi il moltiplicatore restituito è 1
	}
};
