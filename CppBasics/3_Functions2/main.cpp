#include <iostream>
#include <string>

using namespace std;

int naime;

int multiply(int a, int b);

int main(void)
{
  int a, b;
  int c;
  a = 4; b = 9;
  c = multiply(a, b);

  int arrName[4] = {1,2};
  arrName[2] = 3;
  int arr2[] = {1,2,3};
  arr2[4] = 4;
  cout << arr2[6] << endl;

  int* ptr = &a;
  *ptr = b;

  char *f = new char;
  char *m = new char;
  char *l = new char;

  char* initial = new char;
  *initial = *(f);
  *(++initial) = *(m);
  *(++initial) = *(l);

  cout << initial-2 << endl;

  // int, bool, string etc for other types.
  for(int i=0; i<3; i++, initial++)
  {
    cout << initial << endl;
  }

  const int pi = 3.14; // never change!

}

int multiply(int a, int b){
  static int k = 0;
  k++;
  return a*b;
}
