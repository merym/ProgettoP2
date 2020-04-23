#ifndef ARTIFICIERE_H
#define ARTIFICIERE_H

#include "Interfacce/dpsInterface.h"
#include "Interfacce/magicInterface.h"

class Artificiere : public DpsInterface, public MagicInterface{
protected:
    virtual bool increaseLevel(unsigned int newExpPoint);

public:
    Artificiere(QString nome, unsigned int ex): Personaggio(40,20,1,15,"Artificiere",nome,1), DpsInterface(2), MagicInterface(80) {
        while(ex >= 100)
            increaseLevel(ex);
    }
    ~Artificiere() {}
    unsigned int bombardaMaxima();
    unsigned int rainOfSpells();
    unsigned int autodistruzione();
};
const unsigned int MagicInterface::costoManaAbilita1 = 40;
const unsigned int MagicInterface::costoManaAbilita2 = 80;
const unsigned int MagicInterface::costoManaAbilita3 = 140;

#endif // ARTIFICIERE_H
