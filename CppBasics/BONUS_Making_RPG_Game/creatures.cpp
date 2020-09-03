#ifndef CREATURES_CPP
#define CREATURES_CPP

#include "./game.hpp"

// Class :: Method : Init List
Creatures::Creatures(const char cName[], float cHealth) : health(cHealth), isAlive(true) {
  strcpy(name, cName);
}

Creatures::Creatures(const Creatures& C) : health(C.health) {
  strcpy(name, C.name);
}

Creatures::~Creatures() {
  cout << name << " is dead!" << endl;
}

// This will be used to read out health
int Creatures::getHealth(){
  return health;
}

char* Creatures::getName() {
  return name;
}

// Damaged or Healed
void Creatures::setHealth(int cHealth){
  health = cHealth;
}

void Creatures::beDead() {
  isAlive = false;
}

// Reduce health when damage from enemy
void Creatures::damaged(int attackPoint) {
  setHealth(health-attackPoint);
  // When the creature has zero health
  if(health<=0){
    health = 0;
    beDead();
  }
  else {}
}

void Creatures::healed(float healPoint) {
  setHealth(health+healPoint);
}

#endif

