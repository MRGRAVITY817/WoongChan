#include <iostream>
using namespace std;

int peoplePid = 0;

class People{
 private: 
    int age; // Size 4
    int height; // Size 4
    char* name; // Size 8 
    bool current; // Size 1
 public: 
    int pid; // Size 4

    People(){
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

    People(char* name, int age, int height){
      // Overriding Constructor
      // For actual informations!
      this->name = name;
      this->age = age;
      this->height = height;
      pid = peoplePid;
      current = false;
    }

    People(const People& p){
      // Copying Deeply
      this->name = p.name; 
      this->age = p.age; 
      this->height = p.height; 
      this->pid = p.pid; 
      this->current = p.current;
    }

    ~People(){
      // Destructor 
      // This function is called when the object is freed.
      cout << "Bye Bye !" << endl;
    }

    void printPeople(){
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

    void setCurrent(){
      this->current = !(this->current);
    }

    friend void changeCurrentPerson(People* p, int pid);
};

int peopleNumber(People* p);
void changeCurrentPerson(People* p, int pid);
void peopleList(People* p);

int peopleNumber(){
  // If there is no person in list
  return peoplePid;
}

void changeCurrentPerson(People* p, int pid){
  if(p==NULL){
    return;
  }
  
  if(pid>peoplePid-1 || pid<0){
    cout << "Invalid PID.";
    return;
  }
  else{
    int move = pid-(p->pid);
    for(int i=0; i<peoplePid; i++){
      if((p+i)->current){
        (p+i)->setCurrent();
      }
    }
    (p+move)->setCurrent();
    return;
  }
}

void peopleList(People* p){
  int howMuch = peopleNumber();
  if(howMuch==0) return;

  for(int i=0; i<peoplePid; i++){
    (p+i)->printPeople();
  }
}

int main()
{
  system("clear");

  int maxInput;
  cout << "How many people do you want? : ";
  cin >> maxInput;
  People p[maxInput];

  cout << "Continue? (Y/n) : ";
  char cont; cin >> cont;
  if(cont=='y'||cont=='Y'){}
  else return 0;

  while(true){
    system("clear");
    cout << endl
         << "Current people number: " << peopleNumber() << endl
         << "========== People list ==========" << endl;
    peopleList(p);
    cout << "=================================" << endl;
    cout << "Choose Options:" << endl
         << "[1] Add person" << endl
         << "[2] Change current person" << endl
         << "[3] Exit" << endl;
    cout << "Your choice: "; 

    int choice;
    cin >> choice;
    static int i=0;

    if(choice==1){
      if(i>maxInput-1){
        continue;
      }
      char* name = new char; 
      int age, height;
      cout << "New person name: ";
      cin >> name;
      cout << "New person age: ";
      cin >> age;
      cout << "New person height: ";
      cin >> height;
      p[i] = People(name, age, height);
      peoplePid++;
      i++;
    }
    else if(choice==2) {
      int pid;
      cout << "Enter pid to change ";
      cin >> pid;
      changeCurrentPerson(p, pid);
    }
    else if(choice==3) break;
    else{}
  }
  
  return 0;
}

