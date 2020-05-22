#include "headers.hpp"

void forLoop()
{
  system("clear");
  cout << "<< For Loop >>";
  cout << endl << "This will print 1 to 10 using For Loop. " << endl << endl;

  for(int i=1; i<11; i++)
  {
    cout << i << " ";
  }
  yesorno(forLoop);
}

void whileLoop()
{
  system("clear");
  cout << "<< While Loop >>";
  cout << endl << "This will print 1 to 10 using While Loop. " << endl << endl;

  int i = 1;
  while(i<11)
  {
    cout << i << " ";
    i++;
  }
  yesorno(whileLoop);
}
