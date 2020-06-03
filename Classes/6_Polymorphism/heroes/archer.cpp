#ifndef ARCHER_CPP 
#define ARCHER_CPP 

#include "./heroes.cpp"

Archer::Archer(const char _name[])
: Heroes(_name, 85.0f, 10) {}

Archer::~Archer() {}

void Archer::attack(Enemies* E) {
    if(!checkArrows()) {
        if(checkReachable(E)) {
            cout << "Proceeding with Melee attack" << endl;
            cout << "The Archer gave " << dexterity << " damage to " << E->getName() << " !" << endl;
            E->damaged(dexterity);
        }
        else {
            cout << "The Archer cannot reach to the " << E->getName() << " ." << endl;
        }
    }
    else {
        int archerAttack = attackPoint * dexterity * 0.2;
        cout << "The Archer gave " << archerAttack << " damage to " << E->getName() << " !" << endl;
        E->damaged(archerAttack);
    }
}

bool Archer::checkArrows() {
    if(arrows==0) {
        cout << "The Archer is out of arrows! " << endl;
        return false;
    }
    else
    {
        cout << "The Archer has " << arrows << " arrows left. " << endl;
        return true;
    }
}

bool Archer::checkReachable(Enemies* E) {
    if(E->getName()=="Gollem"||E->getName()=="Mushroom") {
        return true;
    }
    else {
        return false;
    }

}

void Archer::sniping(Enemies* E) {
    checkArrows();
    if(arrows < 5) {
        cout << "Not enough arrows for sniping. It should be at least 5 Arrows." << endl;
    }
    else {
        arrows -= 5;
        int snipeAttack = dexterity*attackPoint;
        cout << "The Archer gave " << snipeAttack << " damage to " << E->getName() << " !" << endl;
        E->damaged(snipeAttack);
    }
}

void Archer::damaged(int enemyAttack) {
    if(enemyAttack<=shieldPoint){
        shieldPoint -= enemyAttack;
    }
    // When shield breaks and the hero gets damage
    else{
        float reduced = enemyAttack - shieldPoint;
        shieldPoint = 0;
        setHealth(health-reduced);
        cout << "The Archer got " << reduced << " points of damage (H: " << health << "/100)" << endl;
    }

    // When hero has zero health
    if(health<=0){
        health = 0;
        beDead();
        cout << "The Archer is dead." << endl;
    }
    else {}
}

#endif