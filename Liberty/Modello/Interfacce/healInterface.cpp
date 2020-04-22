#include "personaggio.cpp"

class HealInterface: virtual public Personaggio{
private:
    int blessing; //parte da lvl-1, aumenta per ogni turno di attacco SEMPLICE durante una BATTAGLIA

protected:
    virtual void prayForBlessing(){//chiamato da azione determinata da classe derivata, aumenta blessing
        blessing++;
    }

    void resetBlessing(){
        blessing=getLevel()-1; // da personaggio
    }

    virtual int askForBlessing(){//chiamato per usare il blessing accumulato e fare il reset del blessing
        int result=blessing;
        resetBlessing();
        return result;
    }

    virtual void increaseBlessing(){//chiamato da increaseLevel->(!) must be VIRTUAL! al salire di livello
        resetBlessing();//... RIDONDANZA O CHIAREZZA???
    }

public:
    int getBlessing()const{//ritorna Blessing come VALORE IN LETTURA, usato per fare check di valore
        return blessing;
    }

    virtual bool increaseLevel(const int & newExpPoints){
        bool result= Personaggio::increaseLevel(newExpPoints);//do as normal
        increaseBlessing();//chiama reset con NEWLevel, in entrambi i casi riporta a "zero" il blessing per la prossima BATTAGLIA
        return result;
    }

    /* prima ipotesi
    virtual int attack(){//usato per accumulare blessing, 1 "preghiera" per un colpo; NB potremmo metterlo in personaggio?
        prayForBlessing();
        return Personaggio::GetBaseAttack(); //da personaggio
    }
    */

    virtual int pray(bool use){// può essere usato x accumulare blessing tramite preghiere O per fare "un azione benedetta dalla divinità" azzerando blessing
        if(!use){// add holy juice to tank
            prayForBlessing();
            return 0;
        }
        else{//use holy juice
            int smite=blessing;//valore da ritornare
            resetBlessing();
            return smite;
        }
    }

};
