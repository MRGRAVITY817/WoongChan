#include "headers.hpp"

void yesorno(void (*fptr)())
{ 
  char again;
  cout << endl << "Go Back? (Y/n) : ";
  cin >> again;

  if(again=='Y'||again=='y')
    return;
  else
    fptr();

  return;
}
