#ifndef DEFENCEINTERFACE_H
#define DEFENCEINTERFACE_H

#include "personaggio.h"

class DefenceInterface: virtual public Personaggio{
private:
    unsigned short int turni;
    unsigned int maxArmor;
    static const unsigned short int maxTurni; //aggiunto perchè il prof consigliava sempre di riconoscere le "costanti di classe" negli esercizi
protected:

    virtual unsigned int reducedDamageWithArmor(unsigned int damage) const;

    virtual void incrementaTurni();

    //decrementaturni lo invoca ogni abilit� del personaggio della classe defenceinterface
    //Turni viene decrementato solo quando il personaggio che ha utlizzato l'abilit� BuffArmor � in uso dall'utente
    void decrementaTurni();

    void setMaxArmor(unsigned int arm);

public:

    DefenceInterface(unsigned int m): turni(3), maxArmor(m){}//NB turni dovrebbe essere zero?

    unsigned int getMaxArmor()const;

    unsigned short int getTurni()const;

    //incrementa l'armatura, se non � disponibile l'abilit� (Turni !=0) restituisce false, altrimenti true
    virtual bool buffArmor();
};

#endif // DEFENCEINTERFACE_H

