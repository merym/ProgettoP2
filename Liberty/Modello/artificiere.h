#ifndef ARTIFICIERE_H
#define ARTIFICIERE_H

#include "Interfacce/dpsInterface.cpp"
#include "Interfacce/magicInterface.cpp"
#include "Interfacce/personaggio.cpp"


class Artificiere : public DpsInterface, public MagicInterface{
public:
    Artificiere(QString nome, unsigned int ex): Personaggio(25, 20, 1, 8, "artificiere", nome, 1), DpsInterface(2), MagicInterface(100) {
        while(ex >= 100){   //da fare per ogni personaggio
            increaseLevel(ex);
        }
    }
    ~Artificiere() {}

protected:
    virtual bool increaseLevel(unsigned int newExpPoint) override;
};

#endif // ARTIFICIERE_H
