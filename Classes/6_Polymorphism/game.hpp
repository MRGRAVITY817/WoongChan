#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstring>
using namespace std;

class Creatures{
  protected:
    char name[20];
    float health;
    bool isAlive;

  public:
    Creatures(const char cName[], float cHealth);
    Creatures(const Creatures& C);
    ~Creatures();

    int getHealth();
    char* getName();
    void setHealth(int cHealth);
    void beDead();

    virtual void damaged(int attackPoint);
    virtual void healed(float healPoint);
};


class Heroes : public Creatures {
  protected:
    int attackPoint = 5;
    int shieldPoint = 0;

  public: 
    Heroes(const char hName[], float hHealth, int hAttackPoint);
    ~Heroes();
    void attack(Creatures* C);
    void damaged(int enemyAttack) override;
};

class Enemies : public Creatures {
  protected:
    int attackPoint;
    float stamina;

  public: 
    Enemies(const char eName[], float eHealth);
    ~Enemies();
    void attack(Creatures* C);
    void eatFriend(Creatures* C);
    void damaged(int heroAttack) override;
    void healed(float healPoint) override;
};

#endif
