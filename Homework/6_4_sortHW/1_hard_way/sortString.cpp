#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

void sortArr(string strarr[]);
void printArr(string strarr[]);

int main(){
  system("clear");
  string strarr[8] = {"python", "java", "csharp", "php",
                      "ruby", "electron", "typescript", "shell"};
  cout << "Before sorting: " << endl;
  printArr(strarr);
  cout << "After sorting: " << endl;
  sortArr(strarr);

  return 0;
}

// I used an sorting algorithm called "Selection Sort"
// For more details, search it for your own!
void sortArr(string strarr[]){
  auto start = high_resolution_clock::now();
  for(int i=0; i<8; i++){
    int smallest = i;
    for(int j=i+1; j<8; j++){
      if(strarr[j][0]<strarr[smallest][0])
        smallest = j;
    }
    string tmp = strarr[i];
    strarr[i] = strarr[smallest];
    strarr[smallest] = tmp;
  }
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<nanoseconds>(stop-start);
  printArr(strarr);
  cout << "Time used for sorting: " << duration.count() << " ns " << endl;
}

void printArr(string strarr[]){
  for(int i=0; i<8; i++){
    cout << strarr[i] << " ";
  }
  cout << endl << endl;
}

