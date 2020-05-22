#include "headers.hpp"

void ifElse()
{
  system("clear");
  cout << "<< If / Else if / Else >>" << endl
       << "Choose one of the options below" << endl
       << "1. What is C++?" << endl
       << "2. What is Python?" << endl
       << "3. What is Raspberry Pi?" << endl
       << "4. Exit" << endl;
  cout << "Number: " << endl;

  int choice;
  cin >> choice;

  if(choice==1)
    cout << "C++ is a programming language that enhanced C into more Object Oriented Language" << endl;
  else if(choice==2)
    cout << "Python is an object oriented programming language, specially used for machine learning." << endl;
  else if(choice==3)
    cout << "Raspberry Pi is a multipurpose mini-computer. We will gonna use for the final project!" << endl;
  else if(choice==4)
    return;
  else
    cout << "Bad input :/" << endl;

  yesorno(ifElse);
}

void caseSwitch()
{
  system("clear");
  cout << "<< Switch{case:} >>" << endl
       << "Choose one of the options below" << endl
       << "1. What is C++?" << endl
       << "2. What is Python?" << endl
       << "3. What is Raspberry Pi?" << endl
       << "4. Exit" << endl;
  cout << "Number: " << endl;

  int choice;
  cin >> choice;

  switch(choice)
  {
    case 1:
      cout << "C++ is a programming language that enhanced C into more Object Oriented Language" << endl;
      break;
    case 2: 
      cout << "Python is an object oriented programming language, specially used for machine learning." << endl;
      break;
    case 3:
      cout << "Raspberry Pi is a multipurpose mini-computer. We will gonna use for the final project!" << endl;
      break;
    case 4:
      return;
    default:
      cout << "Bad input :/" << endl;
  }

  yesorno(caseSwitch);
}

void ternaryOp()
{
  system("clear");
  cout << "<< Ternary Operator >>" << endl
       << "Choose one of the options" << endl
       << "choose 1. Life" << endl
       << "choose x. Death" << endl;
  cout << "Your Decision : ";

  int choice;
  cin >> choice;

  string decision = (choice==1) ? "You Live!" : "You Die!";
  cout << decision << endl;

  yesorno(ternaryOp);
}
