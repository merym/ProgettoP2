#include "guaritore.h"

Guaritore::Guaritore(QString nome, unsigned int ex, unsigned int pr): Personaggio(20, 10, 1, 5, "guaritore", nome, pr), HealInterface(){
    while(ex>=100){
        increaseLevel(ex);
        ex-=100;
    }
}

bool Guaritore::increaseLevel(unsigned int newExpPoints){
    bool result= Personaggio::increaseLevel(newExpPoints);//do as normal
    increaseArmor(2+getLevel());
    increaseAttack(2*getLevel());
    increaseMaxHealth(5+getLevel());
    increaseBlessing();//chiama reset con NEWLevel, in entrambi i casi riporta a "zero" il blessing per la prossima BATTAGLIA
    return result;
}

unsigned int Guaritore::useBlessing(){//ridef da healIterf
    unsigned int smite= getBlessing();//valore da ritornare
    smite= smite *getLevel();
    return smite;
}

//add or get juice
unsigned int Guaritore::pray(bool use){
    if(!use){
        prayForBlessing();
        return 0;
    }
    else{
        unsigned int smite=getBlessing() +(getLevel());//Guaritore prende BIG gains in poco tempo, x paladino può essere +lvl invece?
        resetBlessing();
        return smite;
    }
}

unsigned int Guaritore::healingWord(){//usato per guarire se stessi e gli altri
    pray(false);//ad ogni successiva guarigione si guarisce di +
    unsigned int gain=getLevel()+getBlessing();
    receiveHealing(gain);//guarigione su se stessi
    return gain;//guarigione sugli altri: invia il valore x controller o chi deve eseguire il fatto
}

unsigned int Guaritore::smite(){ //usato per attacco benedetto
    return getBaseAttack()+pray(true);
}

unsigned int Guaritore::divineIntervention(){//USATO PER RIPORTARE IN VITA UN PERSONAGGIO CADUTO IN BATTAGLIA
    if(getBlessing()>=3){
        return healingWord()+pray(true);
    }
    else{
        //error, cant use cause no holy(juice) water
        return 0;
    }
}
