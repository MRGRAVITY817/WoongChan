#ifndef ENEMIES_CPP 
#define ENEMIES_CPP 

#include "../game.hpp"

Enemies::Enemies(const char eName[], float eHealth)
: Creatures(eName, eHealth), attackPoint(5), stamina(1.0f) {}

Enemies::~Enemies() {}

void Enemies::attack(Heroes* H) {
  H->damaged(attackPoint);
}

// Sacrifices the friend to get health 
void Enemies::eatFriend(Enemies* E) {
  int sacrifice = E->getHealth();
  healed(sacrifice);
  E->setHealth(0);
}

void Enemies::damaged(int heroAttack) {
  health -= heroAttack/stamina;
}

void Enemies::healed(float healPoint) {
  float healthIncrease = healPoint*stamina; 
  if((health+healthIncrease)>maxHealth){
    setHealth(maxHealth);
    return;
  }
  setHealth(health+healthIncrease);
}

void Enemies::printStatus(){} // This will just override.

class Wyvern : public Enemies {
  private:
    int fireElement;
    bool isReachable;
    bool isFlying;
  
  public:
    Wyvern();
    ~Wyvern();
    void fireball(Heroes* H);
    void damaged(int heroAttack) final;
    void healed(float healPoint) final;
    void printStatus() final;
};

class Gollem : public Enemies {
  private:
    int hardness;
  
  public:
    Gollem();
    ~Gollem();
    void earthquake(Heroes* H1, Heroes* H2, Heroes* H3); 
    void damaged(int heroAttack) final;
    void printStatus() final;
};

class Mushroom : public Enemies {
  private:
    int toxicity;
    int spore;
    Environment* env;

  public: 
    Mushroom(Environment* env);
    ~Mushroom();
    void spreadToxic();
    void babyMushrooms(); // Leaves baby mushrooms when dead;
    void damaged(int heroAttack) final;
    void printStatus() final;
};

class Wraith : public Enemies {
  private:
    float antiLuck;
  
  public:
    Wraith();
    ~Wraith();
    void unfriended(Heroes* H);
    void nightmare(Heroes* H);
    void damaged(int heroAttack) final;
    void printStatus() final;
};

#endif


