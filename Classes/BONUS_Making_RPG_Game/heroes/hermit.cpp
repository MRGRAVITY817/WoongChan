#ifndef HERMIT_CPP
#define HERMIT_CPP

#include "./heroes.cpp"
//We will use this library to use random functions for luck!
#include <random> 
/*
class Hermit : public Heroes {
  private:
    int speed;
    float luck;
    bool isVisible;

  public:
    Hermit(const char _name[]);
    ~Hermit();
    void assassinate(Enemies* E);
    bool sneak();
    bool swtichBack(Enemies* E);
    void printStatus();
};
*/

Hermit::Hermit(const char _name[])
: Heroes(_name, 85.0f, 10) {
  // Add code!
  speed = 5;
  // rollDice() will set the luck value.
  rollDice();
}

Hermit::~Hermit() {}

void Hermit::rollDice(){
  // Generate random machine
  random_device rd;
  mt19937 gen(rd());
  // Use unifrom distribution probability function for random number pick
  uniform_int_distribution<int> dis(0, 99);
  // Assign value to luck
  luck = dis(gen);
}

void Hermit::assassinate(Enemies* E){
  // Add code!
}

bool Hermit::sneak(){
  // Add code!
}

bool Hermit::switchBack(Enemies* E){
  // Add code!
}

void Hermit::printStatus(){
  // Add code!
}

#endif
