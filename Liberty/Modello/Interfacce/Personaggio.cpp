#include "personaggio.h"
    
void Personaggio::increaseMaxHealth(unsigned int addVal){
    maxHealth+= addVal;
    health=static_cast<int>(maxHealth);
} //usato da increaselevel, RESETTA ANCHE HEALTH AL MAX VALUE

void Personaggio::increaseArmor(unsigned int addVal){
    armor+= addVal;
} //usato da increaselevel

void Personaggio::increaseAttack(unsigned int addVal){
    baseAttack+= addVal;
} //usato da increaselevel

void Personaggio::setLevel(unsigned int newLevel){
        level += newLevel;
} //usato da increaselevel (serve ad accedere al campo privato)

void Personaggio::setHealth(int damage){//proposta da healInterf:(int+)= guarigione; (int-)=colpo subito; 0=Dead==true
    health=health + damage;
    if(health<=0){
        kill();
        health=0;
    }
}

void Personaggio::setExp(unsigned int ex){
    expPoint+=ex;
}

unsigned int Personaggio::reducedDamageWithArmor(unsigned int damage) const{ //restituisce il danno ridotto dall'armatura (in defence interface usa maxarmor, invece che armor)
    return damage - (damage*armor)/100;
}

//proposta da healIntef
//per riportare in vita un personaggio, va chiamato DURANTE UNA BATTAGLIA
void Personaggio::resurrect(){
    dead=false;
}
//per uccidere un personaggio dopo setHealth
void Personaggio::kill(){
    dead=true;
}

QString Personaggio::getTipoPersonaggio() const{ return tipoPersonaggio;}
QString Personaggio::getNome() const{ return nome;}
unsigned int Personaggio::getPrezzo() const{return prezzo;}

int Personaggio::getHealth() const{return health;}
unsigned int Personaggio::getMaxHealth() const{return maxHealth;}
unsigned int Personaggio::getBaseAttack() const{return baseAttack;}
unsigned int Personaggio::getLevel() const{return level;}
unsigned int Personaggio::getExpPoint() const{return expPoint;}
unsigned int Personaggio::getArmor() const{return armor;}

bool Personaggio::increaseLevel(unsigned int newExpPoint){//newExpPoint guadagnati dalla vittoria della battaglia
    if(newExpPoint + getExpPoint() >= 100){
        setLevel(1);
        setExp(0);
        return true;
    }
    else{
        setExp(newExpPoint);
    }
    return false;
}

void Personaggio::receiveDamage(unsigned int damage){//utilizza SetHealth e ReducedDamageWithArmor -> varia in base al personaggio; per diminuire HP (hp=hp-damage) tramite setHP
    int dmg= (-1)*static_cast<int>(reducedDamageWithArmor(damage));
    setHealth(dmg);
}

//proposte da healInterf
bool Personaggio::getDeathState() const {return dead;}//in lettura, per il controller

//gain=hp guarita, divineIntervention=is a REZ or NOT
void Personaggio::receiveHealing(unsigned int gain, bool divineIntervention){//chiamato da controller (O da contenitore?) per aumentare Health (hp= hp+gain) tramite setHP
    if(dead==divineIntervention){//valori concordanti, guarigione NORM o REZ
        setHealth(static_cast<int>(gain));
        if(dead)
            resurrect();
}
    else{//valori discordanti
        //ERRORE: non è possibile normale guarigione su cadavere || riportare in vita un personaggio già vivo
    }
}
