#ifndef WARRIOR_CPP 
#define WARRIOR_CPP 

#include "./heroes.cpp"

Warrior::Warrior(const char _name[])
: Heroes(_name, 100.0f, 10) {}

Warrior::~Warrior() {}

void Warrior::attack(Enemies* E) {
    if(isDefensing){
        cout << "The Warrior is defensing now." << endl;
    }
    else {
        int warriorAttack = strength + attackPoint;
        cout << warriorAttack << " points of damage to " << E->getName() << " !" << endl;
        E->damaged(warriorAttack);
    }
}

bool Warrior::defense() {
    isDefensing = !isDefensing;
    return isDefensing;
}

void Warrior::reflectAttack(Enemies* E, int enemyAttack) {
    if(!isDefensing) {
        cout << "The Warrior is not defensing now. " << endl;
    }
    else {
        int warriorAttack = guardPoint*enemyAttack;
        E->damaged(warriorAttack);
    }
}

void Warrior::damaged(Enemies* E, int enemyAttack) {
    if(isDefensing) {
        reflectAttack(E, enemyAttack);
    }
    else {
        if(enemyAttack<=shieldPoint){
            shieldPoint -= enemyAttack;
        }
        // When shield breaks and the hero gets damage
        else{
            float reduced = enemyAttack - shieldPoint;
            reduced = reduced * strength * 0.25;
            shieldPoint = 0;
            setHealth(health-reduced);
            cout << "The Warrior got " << reduced << " points of damage (H: " << health << "/100)" << endl;
        }

        // When hero has zero health
        if(health<=0){
            health = 0;
            beDead();
            cout << "The Warrior is dead." << endl;
        }
        else {}
}

#endif