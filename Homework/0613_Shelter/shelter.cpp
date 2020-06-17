#ifndef SHELTER_CPP 
#define SHELTER_CPP 

#include "main.hpp"

Shelter::Shelter(){
  cout << "How many people do you want? : ";
  cin >> maxPeople;
  this->head = new People[maxPeople];
}

Shelter::~Shelter(){
  cout << "Shelter Destructed" << endl;
}


int Shelter::peopleNumber(){
  return peopleCount;
}

void Shelter::changeCurrentPerson(){
  if(peopleCount==0) return;
  int pid;
  cout << "Enter pid to change ";
  cin >> pid;
  for(int i=0; i<peopleCount; ++i){
    if(head[i].current){
      head[i].setCurrent();
    }
    if(head[i].getPid()==pid){
      head[i].setCurrent();
      return;
    }
  }
  cout << "No current person now." << endl;
  return;
}

void Shelter::peopleList(){
  if(peopleCount==0) return;
  for(int i=0; i<peopleCount; ++i){
    head[i].printPeople();
  }
  return;
}

void Shelter::addPerson(){
    if(peopleCount==maxPeople) return;
    char* name = new char; 
    int age, height;
    cout << "New person name: ";
    cin >> name;
    cout << "New person age: ";
    cin >> age;
    cout << "New person height: ";
    cin >> height;
    head[peopleCount] = People(name, age, height, peopleCount);
    peopleCount++;
}

#endif