#include <iostream>
#include <string>

using namespace std;

void numTypes()
{
  system("clear");

  int num1;
  float num2;
  double num3;

  cout << "<< Size of number types >>" << endl;
  cout << "Size of int : " << sizeof(int) << " bytes" << endl; 
  cout << "Size of float : " << sizeof(float) << " bytes" << endl; 
  cout << "Size of double : " << sizeof(double) << " bytes" << endl; 
  cout << "" << endl;

  cout << "Type Integer : ";
  cin >> num1; 
  cout << "Type Float : ";
  cin >> num2; 
  cout << "Type Double : ";
  cin >> num3; 

  double sum = num1+num2+num3;


  while(true)
  {
    system("clear");

    int choice;
    double sumPrint;

    cout << "<< Number Type Conversion >>" << endl
         << "1. Int" << endl
         << "2. Float" << endl
         << "3. Double" << endl
         << "4. Exit" << endl;
    cout << "Which to convert? : ";
    cin >> choice;

    if(choice==1)
      sumPrint = (int)sum;
    else if(choice==2)
      sumPrint = (float)sum;
    else if(choice==3)
      sumPrint = (double)sum;
    else if(choice==4)
      return;
    else
      cout << "Bad Input :/" << endl;
    
    char again;

    if(choice==1||choice==2||choice==3)
    {
      cout << "Sum of numbers : " << sumPrint << endl;
    }

    cout << endl << "Try again? (Y/n) : " << endl;
    cin >> again; 
    if(again=='Y' || again=='y')
      continue;
    else
      return;
  }
  
  return;
}

void boolTypes()
{
  system("clear");

  bool b = true;
  b = !b;

  cout << "<< Size of Boolean types >>" << endl;
  cout << "Size of bool : " << sizeof(bool) << " bytes" << endl; 
  cout << "" << endl;

  while(true)
  {
    int answer = 4;
    int guess;

    cout << " 2 + 2 = ";
    cin >> guess;

    cout << boolalpha;
    cout << (answer==guess) << endl;

    char again;
    cout << endl << "Try again? (Y/n) : " ;
    cin >> again;

    if(again=='Y'||again=='y')
    {
      system("clear");
      continue;
    }
    else
      break;
  }


  while(true)
  {
    system("clear");

    int choice;
    cout << "<< Logic Operator >>" << endl
         << "1. AND(&&)" << endl
         << "2. OR(||)" << endl
         << "3. NOT(!)" << endl
         << "4. Exit" << endl;
    cout << "Choose the operator : ";
    cin >> choice;

    if(choice==1)
    {
      system("clear");
      cout << boolalpha;
      cout << "<< AND && >>" << endl;
      cout << true << "&&" << true << " = " << (true&&true) << endl 
           << true << "&&" << false << " = " << (true&&false) << endl
           << false << "&&" << false << " = " << (false&&false) << endl;
    }
    else if(choice==2)
    {
      system("clear");
      cout << boolalpha;
      cout << "<< OR || >>" << endl;
      cout << true << "||" << true << " = " << (true||true) << endl 
           << true << "||" << false << " = " << (true||false) << endl
           << false << "||" << false << " = " << (false||false) << endl;
    }
    else if(choice==3)
    {
      system("clear");
      cout << boolalpha;
      cout << "<< NOT ! >>" << endl;
      cout << "!" << true << " = " << (!true) << endl
           << "!" << false << " = " << (!false) << endl;
    }
    else if(choice==4)
      return;
    else
      cout << "Bad Input :/" << endl;
    
    char again;

    cout << endl << "Try Again? (Y/n): ";
    cin >> again; 
    
    if(again=='Y' || again=='y')
      continue;
    else
      return;
  }
  
  return;
}

void charTypes()
{
  system("clear");

  char c;

  cout << "<< Size of Character types >>" << endl;
  cout << "Size of char : " << sizeof(char) << " bytes" << endl << endl; 

  while(true)
  {
    int choice;
    cout << "<< How to assign Char >>" << endl
         << "1. Normal Assignment" << endl
         << "2. ASCII Assignment" << endl
         << "3. Exit" << endl
         << "Choose method : ";
    cin >> choice;

    if(choice==1)
    {
      system("clear");

      cout << endl << "Type any character : ";
      cin >> c;
      cout << "c : " << c << endl;
    }
    else if(choice==2)
    {
      system("clear");
      int ascii;

      cout << "Use the following chart" << endl
           << "https://www.w3schools.com/charsets/ref_html_ascii.asp" << endl << endl;

      cout << endl << "Type anything in ASCII : ";
      cin >> ascii;
      c = ascii;
      cout << "c : " << c << endl; 
    }
    else if(choice==3)
      return;
    else
      cout << "Bad Input :/" << endl;

    char again;

    cout << endl << "Try Again? (Y/n): ";
    cin >> again; 
    
    if(again=='Y' || again=='y')
    {
      system("clear");
      continue;
    }
    else
      return;
  }
  
  return;
}

void stringTypes()
{
  system("clear");

  string charArr;
  cout << "<< Size of String types >>" << endl;
  cout << "Size of string : " << sizeof(string) << " bytes" << endl << endl; 
  
  while(true)
  {
    cin.ignore(32767, '\n');

    cout << endl << "Type the string : ";
    getline(cin, charArr);
    cout << "String: " << charArr << endl;
    cout << "String[3] : " << charArr[3] << endl;
    cout << "String[5] : " << charArr[5] << endl;
    cout << "String[7] : " << charArr[7] << endl;

    char again;

    cout << endl << "Try Again? (Y/n): ";
    cin >> again; 
    
    if(again=='Y' || again=='y')
    {
      system("clear");
      continue;
    }
    else
      return;
  }
  
  return;
}

int main()
{
  int choose;

  while(true)
  {
    system("clear");

    cout << "<< Data Types Practice >>" << endl
         << "Choose one of the following practice: " << endl
         << "1. Number Types" << endl
         << "2. Boolean Types" << endl
         << "3. Character Types" << endl
         << "4. String Types" << endl
         << "5. Exit" << endl << endl;
    cout << "Which Practice? : ";
    cin >> choose;

    if     (choose == 1)
      numTypes();
    else if(choose == 2)
      boolTypes();
    else if(choose == 3)
      charTypes();
    else if(choose == 4)
      stringTypes();
    else if(choose == 5)
      break;
    else
      continue;
  }

  return 0;
}
