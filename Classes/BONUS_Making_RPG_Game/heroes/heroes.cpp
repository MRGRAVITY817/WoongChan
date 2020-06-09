#ifndef HEROES_CPP 
#define HEROES_CPP 

#include "../game.hpp"

Heroes::Heroes(const char hName[], float hHealth, int hAttackPoint) 
: Creatures(hName, hHealth), attackPoint(hAttackPoint){}

Heroes::~Heroes() {}

void Heroes::attack(Creatures* C){
  C->damaged(attackPoint);
}

void Heroes::damaged(int enemyAttack) {
  // When the shield is strong enough to take attack
  if(enemyAttack<=shieldPoint){
    shieldPoint -= enemyAttack;
  }
  // When shield breaks and the hero gets damage
  else{
    shieldPoint = 0;
    setHealth(health-(enemyAttack-shieldPoint));
  }

  // When hero has zero health
  if(health<=0){
    health = 0;
    beDead();
  }
  else {}
}

// It will just override.
void Heroes::printStatus(){}

class Warrior : public Heroes {
  private: 
    int strength = 5;
    float guardPoint = 0.25;
    bool isDefensing = false;

  public:
    Warrior(const char _name[]);
    ~Warrior();
    void attack(Enemies* E); // Not overriding because different arguement type
    bool defense();
    void reflectAttack(Enemies* E, int enemyAttack);
    void damaged(Enemies* E, int enemyAttack); // Final override. No more overriding now!
    void printStatus() final;
};

class Archer : public Heroes {
  private: 
    int dexterity = 5;
    int arrows = 15;
    const int maxArrows = 15;
    float accuracy = 0.76;

  public: 
    Archer(const char _name[]);
    ~Archer();
    void attack(Enemies* E);
    bool checkArrows();
    bool checkReachable(Enemies* E);
    void sniping(Enemies* E);
    void damaged(int enemyAttack) final;
    void printStatus() final;
};

class Wizard : public Heroes {
  private:
    int intelligence = 5;
    float magicka = 50;
    const int maxMagicka = 50;

  public:
    Wizard(const char _name[]);
    ~Wizard();
    void charm(Enemies* E1, Enemies* E2, Enemies* E3);
    void healHero(Heroes* H);
    void ressurection(float luck, Heroes* H);
    void meditate();
    bool isMagicable(int skill);
    void printStatus() final;
};

class Hermit : public Heroes {
  private:
    int speed;
    int luck;
    bool isVisible;

  public:
    Hermit(const char _name[]);
    ~Hermit();
    void rollDice();
    void assassinate(Enemies* E);
    bool sneak();
    bool switchBack(Enemies* E);
    void printStatus() final;
};

#endif
