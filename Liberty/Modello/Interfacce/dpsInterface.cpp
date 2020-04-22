#include "personaggio.cpp"
#include <cstdlib> //per rand()
#include <ctime> //per time()

class DpsInterface: virtual public Personaggio{
private:
    //ProbCritico diminuisce all'aumentare del livello del personaggio --> aumenta la probabilit� di effettuare un colpo critico
    //se all'inizio � 5, la prob. di ottenere un critico � 1/5, diminuendolo aumenta la probabilit�
    int probCritico;
protected:

    //il metodo per aumentare la probabilit� si chiama INCREASE anche se di fatto decrementa il parametro per farlo.
    void increaseProbCritico(){
      //Check (utile?)
      if(probCritico>2)
        probCritico--;
    }
    int critico() const{
      //la prossima riga serve per i numeri random
      srand(time(NULL));
      //rand()%ProbCritico genera un numero casuale [0,ProbCritico-1], se esce 0 (probabilit�=1/ProbCritico) si ottiene un critico
      //esempio: se ProbCritico � 5, si genera un numero [0,4]
      if((rand()%probCritico)==0)
        return 3+getLevel(); //viene restituito un intero che sar� usato per moltiplicare il danno fatto
      else
        return 1; //se non esce 0, non si ottiene un critico; quindi il moltiplicatore restituito � 1
    }
public:
    DpsInterface(int pc): probCritico(pc) {}
};
