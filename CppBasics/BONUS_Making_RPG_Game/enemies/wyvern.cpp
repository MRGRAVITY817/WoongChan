#ifndef WYVERN_CPP
#define WYVERN_CPP

#include "./enemies.cpp"
#include "../heroes/heroes.cpp"

Wyvern::Wyvern()
: Enemies("Wyvern", 150.0f) {
    stamina = 5.0f;
    attackPoint = 15;
}

Wyvern::~Wyvern() {}

void Wyvern::fireball(Heroes* H){
    cout << attackPoint << "points of damage to " << H->getName() << " !" << endl;
    if(H->getName()=="Warrior"){
        Warrior* W = (Warrior*)H;
        W->damaged(this, attackPoint);
        return;
    }
    else{
        H->damaged(attackPoint);
        return;
    }
}

void Wyvern::damaged(int heroAttack){
    float reduced = heroAttack - heroAttack*stamina*0.1;
    setHealth(health-reduced);
    cout << "The Wyvern got " << reduced << " points of damage (H: " << health << "/100)" << endl;

    // When hero has zero health
    if(health<=0){
        health = 0;
        beDead();
        cout << "The Wyvern is dead." << endl;
    }
    else {}
}


#endif