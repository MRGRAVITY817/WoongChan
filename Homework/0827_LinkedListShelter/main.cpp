#include "main.hpp"

int main()
{
  system("clear");

  bool isFirst = true;
  while(true){
    Shelter* fallout = new Shelter;
    cout << "Continue? (Y/n) : ";
    char cont; cin >> cont;
    if(cont=='y'||cont=='Y'){}
    else return 0;
    while(true){
      system("clear");
      cout << endl
          << "Current people number: " << fallout->peopleNumber() << endl
          << "========== People list ==========" << endl;
      fallout->peopleList();
      cout << "=================================" << endl;
      cout << "Choose Options:" << endl
          << "[1] Add person" << endl
          << "[2] Change current person" << endl
          << "[3] Change current person's Pid" << endl
          << "[4] Remove current person" << endl
          << "[5] Resize the shelter" << endl
          << "[6] Exit" << endl;
      cout << "Your choice: "; 

      int choice;
      cin >> choice;

      if(choice==1){
        fallout->addPerson();
      }
      else if(choice==2) {
        fallout->changeCurrentPerson();
      }
      else if(choice==3){
        fallout->changePid();
      }
      else if(choice==4){
        fallout->removePeople();
      }
      else if(choice==5){
        fallout->resizeShelter();
      }
      else if(choice==6) break;
      else{}
    }
  }
  return 0;
}

