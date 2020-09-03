#ifndef GOLLEM_CPP
#define GOLLEM_CPP

#include "./enemies.cpp"
/*
class Gollem : public Enemies {
  private:
    int hardness;
  
  public:
    Gollem(const char _name[], float _health);
    ~Gollem();
    void earthquake(Heroes* H1, Heroes* H2, Heroes* H3); 
    void damaged(int heroAttack) final;
};
*/

Gollem::Gollem()
: Enemies("Gollem", 200.0f){
    stamina = 7.0f;
    attackPoint = 10;
    maxHealth = 200;
}

Gollem::~Gollem(){}

void Gollem::earthquake(Heroes* H1, Heroes* H2, Heroes* H3){
    cout << attackPoint << "points of damage to " << H1->getName() << " !" << endl;
    cout << attackPoint << "points of damage to " << H2->getName() << " !" << endl;
    cout << attackPoint << "points of damage to " << H3->getName() << " !" << endl;
    
    H1->damaged(attackPoint);
    H2->damaged(attackPoint);
    H3->damaged(attackPoint);
}

void Gollem::damaged(int heroAttack){
    float reduced = heroAttack - heroAttack*stamina*0.1;
    setHealth(health-reduced);
    cout << "The Gollem got " << reduced << " points of damage (H: " << health << "/100)" << endl;

    // When hero has zero health
    if(health<=0){
        health = 0;
        beDead();
        cout << "The Gollem is dead." << endl;
    }
    else {}
}

void Gollem::printStatus(){
    cout << name << " "
         << "HP: " << health << "/" << maxHealth << " ";
    if(!isAlive){
        cout << "[DEAD]" << endl;
        return;
    }
}

#endif 