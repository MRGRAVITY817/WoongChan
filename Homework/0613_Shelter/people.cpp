#ifndef PEOPLE_CPP
#define PEOPLE_CPP

#include "main.hpp"

People::People(){
    // Constructor
    // Just for allocating memory :)
    cout << "====== Memory Allocation ======" << endl;
    cout << sizeof(this->age) << " + " 
        << sizeof(this->height) << " + "
        << sizeof(this->name) << " + "
        << sizeof(this->current) << " + "
        << sizeof(this->pid) << " + extra spaces = "
        << sizeof(*this) << endl;
    cout << "===============================" << endl;
}

People::People(char* name, int age, int height, int pid){
    // Overriding Constructor
    // For actual informations!
    this->name = name;
    this->age = age;
    this->height = height;
    this->pid = pid;
    current = false;
}

People::People(const People& p){
    // Copying Deeply
    this->name = p.name; 
    this->age = p.age; 
    this->height = p.height; 
    this->pid = p.pid; 
    this->current = p.current;
}

People::~People(){
    // Destructor 
    // This function is called when the object is freed.
    cout << "Bye Bye !" << endl;
}

int People::getPid(){
    return pid;
}
void People::setPid(int _pid){
    pid = _pid;
    return;
}

void People::printPeople(){
    cout << this->pid << " " 
        << this->name << " "
        << this->age << "years old "
        << this->height << "cm";
    if(current){
    cout << "  <-" << endl;
    }
    else{
    cout << endl;
    }
}

void People::setCurrent(){
    this->current = !(this->current);
}

char* People::getName(){
    return this->name;
}

void People::getOut(){
    this->name = NULL;
    this->age = -1;
    this->height = -1;
    this->pid = -1;
    this->current = false;
}

#endif