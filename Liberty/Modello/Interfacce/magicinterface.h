#ifndef MAGICINTERFACE_H
#define MAGICINTERFACE_H

#include "personaggio.cpp"

class MagicInterface: virtual public Personaggio{
private:
    unsigned int maxMana;	//mana disponibile all'inizio dello scontro per ogni mago (massimo) UGUALE PER TUTTI -> usato da increaseLevel() -> aumenta col livello
    unsigned int mana;	//mana che si aggiorna ogni volta che si lancia un'abilità; inizialmente uguale a maxMana
    //costo delle abilita' delle classi figlie (mago, artificiere)

    static const unsigned int costoManaAbilita1;
    static const unsigned int costoManaAbilita2;
    static const unsigned int costoManaAbilita3;
protected:
    virtual void increaseMaxMana(unsigned int addVal);

public:
    /*MagicInterface(unsigned int mH, unsigned int bA, unsigned int lv, unsigned int a, QString t, QString n, unsigned int p, unsigned int m):
        Personaggio(mH, bA, lv, a, t, n, p), maxMana(m), mana(m) {}*/
    MagicInterface(unsigned int m): maxMana(m), mana(m) {}
    virtual ~MagicInterface() {}
    unsigned int getMaxMana() const;
    unsigned int getMana() const;
    bool isThrowable(unsigned int m) const;
    void setMana(unsigned int m);
    void resetMana();

    unsigned int getCostoA1() const {return costoManaAbilita1;}
    unsigned int getCostoA2() const {return costoManaAbilita2;}
    unsigned int getCostoA3() const {return costoManaAbilita3;}
};


#endif // MAGICINTERFACE_H
