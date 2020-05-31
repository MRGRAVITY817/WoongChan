#include <iostream>
using namespace std;

class Person{
 public: 
    char* name;
    int age;
    double height;
    int pid;
    // Constructor
    Person()
    {}
    Person(char* name, int age, double height, int pid){
      this->name = name;
      this->age = age;
      this->height = height;
      this->pid = pid;
    }
};

class People{
  private:
    Person* p;
  public:
    People(){}
    int peopleNumber();
    void changeCurrentPerson(int pid);
    void addPerson();
    char* currentPerson();
    void peopleList();
};

int People::peopleNumber(){
  // If there is no person in list
  if(this->p==NULL){
    return 0;
  }

  int countNum = 1;
  // Add more when there's more people
  while(this->p->pid!=0){
    countNum++;
  }
  
  if(countNum==1){
    cout << countNum << " person in people list!" << endl;
  }
  else{
    cout << countNum << " people in people list!" << endl;
  }

  return countNum;
}

void People::changeCurrentPerson(int pid){
  if(p==NULL){
    cout << "No one in people list!" << endl;
    return;
  }
  
  if(pid>peopleNumber() || pid<1){
    cout << "Invalid PID.";
    return;
  }
  else{
    int move = pid-(p->pid);
    p = p+move;
    return;
  }
}

void People::addPerson(){
  char* pName;
  int pAge, pHeight, pID;
  // Get user input for new person.
  cout << "New person name: ";
  cin >> pName;
  cout << "New person age: ";
  cin >> pAge;
  cout << "New person height: ";
  cin >> pHeight;
  
  // New pid for new person.
  if(this->p==NULL) pID = 0;
  else{
    pID = this->p->pid + 1;
  }
  cout << endl << pID << endl;
  // Construct new person. 
  Person newPerson(pName, pAge, pHeight, pID);
  // Add new person at the next address of this pointer-list.
  ++this->p = &newPerson; 
}

char* People::currentPerson(){
  if(this->p == NULL) return "none";
  return this->p->name;
}

void People::peopleList(){
  int howMuch = peopleNumber();

  if(howMuch==0) return;

  for(int i=0; i<peopleNumber(); i++)
  {
    cout << this->p->pid << ") " 
         << this->p->name << " "
         << this->p->age << "yrs old "
         << this->p->height << "cm"<< endl;
    this->p++;
  }
}

int main()
{
  People students;
  while(true){
    system("clear");
    cout << endl
         << "Current people number: " << students.peopleNumber() << endl
         << "Current person : " << students.currentPerson() << endl
         << "====== Current people list ======" << endl;
    students.peopleList();
    cout << "=================================" << endl;
    cout << "Choose Options:" << endl
         << "[1] Add person" << endl
         << "[2] Change current person" << endl
         << "[3] Exit" << endl;

    int stop;
    cin >> stop;

    if(stop==1) students.addPerson();
    else if(stop==2) {
      int pid;
      cout << "Enter pid to change ";
      cin >> pid;
      students.changeCurrentPerson(pid);
    }
    else if(stop==3) return 0;
    else{
    }
  }
  return 0;
}

