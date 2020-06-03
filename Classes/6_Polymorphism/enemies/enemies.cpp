#ifndef ENEMIES_CPP 
#define ENEMIES_CPP 

#include "../game.hpp"

Enemies::Enemies(const char eName[], float eHealth)
: Creatures(eName, eHealth), attackPoint(5), stamina(1.0f) {}

Enemies::~Enemies() {}

void Enemies::attack(Creatures* C) {
  C->damaged(attackPoint);
}

// Sacrifices the friend to get health 
void Enemies::eatFriend(Creatures* C) {
  int sacrifice = C->getHealth();
  healed(sacrifice);
  C->setHealth(0);
}

void Enemies::damaged(int heroAttack) {
  health -= heroAttack/stamina;
}

void Enemies::healed(float healPoint) {
  health += healPoint*stamina; 
}

class Wyvern : public Enemies {
  private:
    int fireElement;
    bool isReachable;
    bool isFlying;
  
  public:
    Wyvern(const char _name[], float _health);
    ~Wyvern();
    void fireball(Heroes* H);
    void damaged(int heroAttack) final;
    void healed(float healPoint) final;
};

class Gollem : public Enemies {
  private:
    int hardness;
  
  public:
    Gollem(const char _name[], float _health);
    ~Gollem();
    void earthquake(Heroes* H1, Heroes* H2, Heroes* H3); 
    void damaged(int heroAttack) final;
};

class Mushroom : public Enemies {
  private:
    int toxicity;
    int spore;

  public: 
    Mushroom(const char _name[], float _health);
    ~Mushroom();
    void spreadToxic();
    int babyMushrooms(); // Leaves baby mushrooms when dead;
    void damaged(int heroAttack) final;
};

class Wraith : public Enemies {
  private:
    float antiLuck;
  
  public:
    Wraith(const char _name[], float _health);
    ~Wraith();
    void unfriended(Heroes* H);
    void nightmare(Heroes* H);
    void damaged(int heroAttack) final;
};

#endif


