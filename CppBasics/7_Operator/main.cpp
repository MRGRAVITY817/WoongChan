#include <iostream>
using namespace std;

enum class Drinks{
  Americano,
  Latte, 
  Sugar_Milk,
  Bubble_Tea
};

// HOMEWORK!
// Getting members from enum class looks complicated.
// Will there be any other way to simplify? Find it how, and replace the
// parts in "Drinks operator+" function!
// Ex) Drinks::Americano -> ?

enum Ingredients{
  Coffee_Bean,
  Water,
  Milk,
  Pearl,
  Sugar
};

// HOMEWORK!
// Make an extra overloading operator function to simplify
// "I1==Something && I2==Something" part.

Drinks operator+(Ingredients I1, Ingredients I2){
  Drinks D;
  if(I1==Coffee_Bean && I2==Water)  D = Drinks::Americano;
  else if(I1==Coffee_Bean && I2==Milk) D = Drinks::Latte;
  else if(I1==Sugar && I2==Milk) D = Drinks::Sugar_Milk;
  else if(I1==Pearl && I2==Milk) D = Drinks::Bubble_Tea;
  return D;
}

// HOMEWORK!!
// Making printDrink function is exhasting...
// Aren't there other ways to do more simple?
void printDrink(Drinks D){
  switch(D){
    case Drinks(0): 
      cout << "Americano! "; break;
    case Drinks(1): 
      cout << "Latte! "; break;
    case Drinks(2): 
      cout << "Sugar Milk! "; break;
    case Drinks(3):
      cout << "Bubble Tea! "; break;
    default:
      cout << "Hmmm..is it a drink?? "; break;
  }
}

int main(){
  Drinks D[4];
  D[0] = Coffee_Bean + Water;
  D[1] = Coffee_Bean + Milk;
  D[2] = Sugar + Milk;
  D[3] = Pearl + Milk; 

  for(int i=0; i<4; ++i){
    printDrink(D[i]);
  }
  cout << endl;

  return 0;
}



