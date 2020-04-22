#include "Modello/Interfacce/healInterface.cpp"


class Guaritore: public HealInterface{
public:

    /*prima ipotesi
    virtual int useBlessing(){//ridef da healIterf
        int smite= HealInteface::useBlessing();//valore da ritornare
        smite= smite *getLevel();
        return smite;
    }
    */
    //add or get juice
    virtual int pray(bool use){
        if(!use){
            prayForBlessing();
        }
        else{
            int smite=blessing *(getLevel()/2);//guaritore prende BIG gains in poco tempo, x paladino può essere +lvl invece?
            resetBlessing();
            return smite;
        }
    }

    int healingWord(){//usato per guarire se stessi e gli altri
        pray(false);//ad ogni successiva guarigione si guarisce di +
        int gain=getLevel()+getBlessing();
        receiveHealing(gain);//guarigione su se stessi
        return gain;//guarigione sugli altri: invia il valore x controller o chi deve eseguire il fatto
    }

    int smite(){ //usato per attacco benedetto
        return getBaseAttack()+pray(true);
    }

    int divineIntervention(){//USATO PER RIPORTARE IN VITA UN PERSONAGGIO CADUTO IN BATTAGLIA
        if(getBlessing()>=3){
            return healingWord()+pray(true);
        }
        else{
            //error, cant use cause no holy(juice) water
        }
    }

};
