#include <iostream>
#include <string>
using namespace std;

void printArray(int* a, bool* b, char* c, string* d){

  system("clear");
  
  cout << endl;
  cout << "INT array (4 byte)" << endl;
  for(auto i=0; i<4; i++, a++)
  {
    cout << "[" << a << "] " << *a << endl; 
  }

  cout << endl;
  cout << "BOOL array (1 byte)" << endl;
  cout << boolalpha;
  for(auto j=0; j<4; j++, b++)
  {
    cout << "[" << b << "] " << *b << endl; 
  }

  cout << endl;
  cout << "CHAR array (1 byte)" << endl;
  for(auto k=0; k<4; k++, c++)
  {
    cout << "[" << (void*)c << "] " << *c << endl; 
  }

  cout << endl;
  cout << "STRING array (32 byte)" << endl;
  for(auto l=0; l<4; l++, d++)
  {
    cout << "[" << d << "] " << *d << endl; 
  }

}
/*
void printOneArray(auto autoArr)
{
  cout << endl;
  cout << "Array (" << sizeof(*autoArr) << "byte)" << endl;
  for(auto i=0; i<4; i++, autoArr++)
  {
    cout << "[" << (void*)autoArr << "] " << *autoArr << endl; 
  }
}
*/

int main(){

  system("clear");
  
  int intArr[4] = {1,2,3,4};
  bool boolArr[4] = {true, false, false, true};
  char charArr[4] = {'c','h','a','n'};
  string strArr[4] = {"Hello ","Array, ","Hello ", "Pointer!"};

  printArray(intArr, boolArr, charArr, strArr);
  /*
  printOneArray(intArr);
  printOneArray(boolArr);
  printOneArray(charArr);
  printOneArray(strArr);
  */

  return 0;
}
