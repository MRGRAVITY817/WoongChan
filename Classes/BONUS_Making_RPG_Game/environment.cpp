#ifndef ENVIRONMENT_CPP
#define ENVIRONMENT_CPP

#include "./game.hpp"

// Constructor
Environment::Environment
(Heroes *Warrior, Heroes *Archer, Heroes *Wizard, Heroes *Hermit,
Enemies *Wyvern, Enemies *Gollem, Enemies *Mushroom, Enemies *Wraith){
    // Heroes
    this->Warrior = Warrior; 
    this->Archer = Archer; 
    this->Wizard = Wizard; 
    this->Hermit = Hermit; 
    // Enemies
    this->Wyvern = Wyvern; 
    this->Gollem = Gollem; 
    this->Mushroom = Mushroom; 
    this->Wraith = Wraith; 
}

Environment::Environment(const Environment& env){
    // Heroes
    this->Warrior = env.Warrior; 
    this->Archer = env.Archer; 
    this->Wizard = env.Wizard; 
    this->Hermit = env.Hermit; 
    // Enemies
    this->Wyvern = env.Wyvern; 
    this->Gollem = env.Gollem; 
    this->Mushroom = env.Mushroom; 
    this->Wraith = env.Wraith; 
}
    
Environment::~Environment(){}

void Environment::setPollution(float _pollution){
    pollution = _pollution;
    // The pollution will damage bionic creatures (heroes & wyvern)
    Warrior->damaged(pollution);
    Archer->damaged(pollution);
    Wizard->damaged(pollution);
    Hermit->damaged(pollution);
    Wyvern->damaged(pollution);
    // Then the pollution goes back to 0
    pollution = 0;
}

void Environment::printEnv(){
    cout << "======= Heroes status =======" << endl;
    Warrior->printStatus();
    Archer->printStatus();
    Wizard->printStatus();
    Hermit->printStatus();
    cout << endl;
    cout << "======= Enemies status =======" << endl;
    Wyvern->printStatus();
    Gollem->printStatus();
    Mushroom->printStatus();
    Wraith->printStatus();
    cout << endl;
}
    

#endif