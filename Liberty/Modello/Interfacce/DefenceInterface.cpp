#include "personaggio.cpp"
class DefenceInterface: virtual public Personaggio{
private:
    int turni;
    int maxArmor;
protected:
    virtual void incrementaTurni(){
      turni=3;
    }
    //decrementaturni lo invoca ogni abilit� del personaggio della classe defenceinterface
    //Turni viene decrementato solo quando il personaggio che ha utlizzato l'abilit� BuffArmor � in uso dall'utente
    void decrementaTurni(){
        if(turni!=0){
        turni--;
        setMaxArmor(getArmor());
        }
    }
    void setMaxArmor(const int& arm){
        maxArmor=arm;
    }
public:
    //incrementa l'armatura, se non � disponibile l'abilit� (Turni !=0) restituisce false, altrimenti true
    virtual bool buffArmor(){
        if(turni!=0)
            return false;
        setMaxArmor(getArmor()+3*getLevel());
        return true;
    }
};
