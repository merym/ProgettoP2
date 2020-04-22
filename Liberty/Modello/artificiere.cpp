#include "artificiere.h"

bool Artificiere::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
  if(newExpPoint + getExpPoint() >= 100){
    Personaggio::increaseLevel(newExpPoint);
    increaseMaxHealth(getMaxHealth()+5*getLevel());
    increaseArmor(getArmor()+3*getLevel());
    increaseAttack(getBaseAttack()+6*getLevel());
    increaseProbCritico();
    increaseMaxMana(getMana()+15*getLevel());
    return true;
  }
  else {
      return false;
  }
}
