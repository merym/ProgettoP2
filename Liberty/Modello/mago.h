#ifndef MAGO_H
#define MAGO_H

#include "Interfacce/magicInterface.h"

class Mago: public MagicInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    /*Mago(QString nome, unsigned int ex): MagicInterface(40,20,1,15,"Mago",nome,1,100){ //ultimo parametro = maxMana iniziale
        while(ex >= 100)
            increaseLevel(ex);
    }*/

    Mago(QString nome, unsigned int ex): Personaggio(40,20,1,15,"Mago",nome,1), MagicInterface(100){
        while(ex >= 100)
            increaseLevel(ex);
    }
    virtual ~Mago() {}
    unsigned int expelliarmus();
    unsigned int expectoPatronum();
    unsigned int avadaKedavra();
};
const unsigned int MagicInterface::costoManaAbilita1 = 50;
const unsigned int MagicInterface::costoManaAbilita2 = 90;
const unsigned int MagicInterface::costoManaAbilita3 = 130;

#endif // MAGO_H
