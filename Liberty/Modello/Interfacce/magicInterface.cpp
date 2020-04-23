#include "magicinterface.h"

//usato da increaselevel
void MagicInterface::increaseMaxMana(unsigned int addVal){
    maxMana = addVal;
}

unsigned int MagicInterface::getMaxMana() const {return maxMana;}

unsigned int MagicInterface::getMana() const {return mana;}

bool MagicInterface::isThrowable(unsigned int m) const{ //controlla se il mago ha il mana necessario per lanciare l'abilità
    if(mana < m)
        return false;
    return true;
}

//aggiorna il mana dopo il lancio di un'abilità
void MagicInterface::setMana(unsigned int m){
    mana -= m;
}

//per ripristinare il mana alla fine di uno scontro, anche se non è aumentato di livello
void MagicInterface::resetMana(){
    mana = maxMana;
}
