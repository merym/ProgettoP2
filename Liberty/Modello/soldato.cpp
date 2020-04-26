#include "soldato.h"

bool Soldato::increaseLevel(unsigned int newExpPoint){
    if(newExpPoint + getExpPoint() >= 100){
        Personaggio::increaseLevel(newExpPoint);
        increaseMaxHealth(5*getLevel());
        increaseArmor(4*getLevel());
        increaseAttack(5*getLevel());
        increaseProbCritico();
        return true;
    }
    else{
        return false;
    }
}

//IL fatto di impedire di usare un metodo per un tot di turni si fa con la GUI
unsigned int Soldato::pugnoFurtivo(){
    return 2*getBaseAttack()*critico()+getLevel();
}

unsigned int Soldato::fendente(){
    return (3*getBaseAttack()*critico()+getLevel())+3;
}

unsigned int Soldato::coltellata(){
    return 2*getBaseAttack()*critico()+getLevel()*3;
}
