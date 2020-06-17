#include <iostream>
using namespace std;

void sortArr(int* intArr);
void printArr(int* intArr);

int main(){
  // Dynamic memory allocation for Int array-pointer.
  int* intArr = new int;
  while(true){
    system("clear");
    cout << endl 
         << "< Sorting INT! >" << endl
         << "Step 1) Type integers (5 times): " << endl;
    
    // Get input 5 integers from user.
    for(int i=0; i<5; i++, intArr++)
    {
      cout << "INT " << i << ": ";
      cin >> *intArr; 
    }
    intArr = intArr-5;

    printArr(intArr);

    cout << "Options: " << endl
         << "1) Sort the array elements" << endl
         << "2) Exit" << endl;
    cout << "Your choice: ";
    int choice;
    cin >> choice;

    if(choice==2) return 0;
    else if(choice==1){
      sortArr(intArr);
      
      cout << "AGAIN? (Y/n): ";
      char yesorno;
      cin >> yesorno;
      if(yesorno=='y' || yesorno=='Y')
        continue;
      else
        return 0;
    }
    else {}
  }
  return 0;
}

// This function sorts the elements in the array.
// The special sorting algorithm called "selection sort"
// is used, but we will learn later :)
void sortArr(int* intArr){
  // Add your code here! 
  for(int i=0; i<5; i++){
    int smallest = i;
    for(int j=i+1; j<5; j++){
      if(*(intArr+j)<*(intArr+smallest))
        smallest = j;
    }
    int tmp = *(intArr+i);
    *(intArr+i) = *(intArr+smallest);
    *(intArr+smallest) = tmp;
  }
  printArr(intArr);
  return;
}

// This function will print the array.
void printArr(int* intArr){
  cout << "Your Int Array is [ ";
  for(int i=0; i<5; i++){
    cout << *(intArr+i) << " ";
  }
  cout << "]" << endl;
}
