#include "headers.hpp"

int main()
{
  while(true)
  {
    system("clear");
    cout << endl << "<< Practice! >>" << endl;
    cout << "[LOOPS]" << endl
         << "1. For loop" << endl
         << "2. While loop" << endl
         << "[CONDITIONS]" << endl
         << "3. If/Else" << endl
         << "4. Switch/Case" << endl
         << "5. Ternary Operator" << endl
         << "6. Exit" << endl;
    cout << endl << "Which one? : ";

    int choice;
    cin >> choice;

    switch(choice){
      case 1:
        forLoop(); break;
      case 2:
        whileLoop(); break;
      case 3:
        ifElse(); break;
      case 4:
        caseSwitch(); break;
      case 5:
        ternaryOp(); break;
      case 6:
        return 0;
      default:
        continue;
    }
  }

  return 0;
}
