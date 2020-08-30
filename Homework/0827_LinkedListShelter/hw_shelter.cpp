#ifndef HW_SHELTER_CPP 
#define HW_SHELTER_CPP 

#include "main.hpp"

void Shelter::changePid(){
  int pid;
  cout << "Which pid do you want? : ";
  cin >> pid;

  for(int i=0; i<peopleCount; ++i){
    if(head[i].getPid()==pid){
      char choice;
      cout << "Required pid already exists. Try again? (Y/n): " ;
      cin >> choice;
      if(choice=='Y' || choice=='y') changePid();
      else return;
    }
  }

  for(int i=0; i<peopleCount; ++i){
    if(head[i].current){
      head[i].setPid(pid);
      cout << head[i].getName() << " changed pid to " << pid << " ." << endl;
      return;
    }
  }
  cout << "There is no current person." << endl;
  return; 
}

void Shelter::removePeople(){
  char choice;
  cout << "Remove current person? (Y/n): " ;
  cin >> choice;
  if(choice=='Y' || choice=='y') {}
  else return;
  for(int i=0; i<peopleCount; ++i){
    if(head[i].current) {
      for(int j=i; j<peopleCount-1; ++j){
        head[j] = head[j+1];
      }
      head[peopleCount].getOut();
      peopleCount--;
      return;
    }
  }
  return;
}

void Shelter::resizeShelter(){
  // Get the input for new size
  cout << "Which size to resize the shelter? : " ;
  int sizeValue;
  cin >> sizeValue;
  
  while(peopleCount>sizeValue){
    cout << "Who do you want to say good bye? (choose with pid) : ";
    int goodbyepid;
    cin >> goodbyepid;
    for(int i=0; i<peopleCount; ++i){
      if(head[i].getPid()==goodbyepid){
        for(int j=i; j<peopleCount-1; ++j){
          head[j] = head[j+i];
        }
        peopleCount--;
        break;
      }
    }
  }

  People* newShelter = new People[sizeValue];
  for(int i=0; i<sizeValue; ++i){
    newShelter[i] = head[i];
  }

  delete[] head;
  this->head = newShelter;
  this->maxPeople = sizeValue;
}

#endif