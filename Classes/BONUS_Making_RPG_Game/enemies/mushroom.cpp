#ifndef MUSHROOM_CPP
#define MUSHROOM_CPP

#include "./enemies.cpp"

Mushroom::Mushroom(Environment* env)
: Enemies("Mushroom", 50){
    stamina = 1.0f;
    attackPoint = 5.0f;
    toxicity = 1;
    spore = 1;
    this->env = env;
}

Mushroom::~Mushroom() {}

void Mushroom::spreadToxic(){
    float pollution = toxicity*spore*0.1;
    cout << "Spreading " << spore << " spores in the air!" << endl;
    env->setPollution(pollution);
}

void Mushroom::babyMushrooms(){
    cout << "Mushroom spores left : " << spore << endl;
    spreadToxic();
    spore--;
}

void Mushroom::damaged(int heroAttack){
    float reduced = heroAttack - heroAttack*stamina*0.1;
    setHealth(health-reduced);
    cout << "The Mushroom got " << reduced << " points of damage (H: " << health << "/50)" << endl;

    // When hero has zero health
    if(health<=0){
        health = 0;
        beDead();
        cout << "The Mushroom exploded, and the spores are spreading!" << endl;
        babyMushrooms();
    }
    else {}
}

#endif