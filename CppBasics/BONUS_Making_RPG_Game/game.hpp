#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Creatures{
  protected:
    char name[20];
    float health;
    int maxHealth = 100; 
    bool isAlive;

  public:
    Creatures(const char cName[], float cHealth);
    Creatures(const Creatures& C);
    ~Creatures();

    int getHealth();
    char* getName();
    void setHealth(int cHealth);
    void beDead();

    virtual void printStatus();
    virtual void damaged(int attackPoint);
    virtual void healed(float healPoint);
};


class Heroes : public Creatures {
  protected:
    int attackPoint = 5;
    int shieldPoint = 0;
    int maxShieldPoint = 10;

  public: 
    Heroes(const char hName[], float hHealth, int hAttackPoint);
    ~Heroes();
    void attack(Creatures* C);
    void damaged(int enemyAttack) override;
    void printStatus() override;
};

class Enemies : public Creatures {
  protected:
    int attackPoint;
    float stamina;

  public: 
    Enemies(const char eName[], float eHealth);
    ~Enemies();
    void attack(Heroes* H);
    virtual void eatFriend(Enemies* E);
    void damaged(int heroAttack) override;
    void healed(float healPoint) override;
    void printStatus() override;
};

class Environment{
  protected:
    float pollution = 0;
    Heroes *Warrior, *Archer, *Wizard, *Hermit; 
    Enemies *Wyvern, *Gollem, *Mushroom, *Wraith;

  public:
    Environment(Heroes *Warrior, Heroes *Archer, Heroes *Wizard, Heroes *Hermit,
                Enemies *Wyvern, Enemies *Gollem, Enemies *Mushroom, Enemies *Wraith);
    Environment(const Environment& env);
    ~Environment();
    void setPollution(float _pollution);
    void printEnv();
};

#endif
