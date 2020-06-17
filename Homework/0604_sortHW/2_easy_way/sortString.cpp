#include <iostream>
#include <string>
#include <vector> // For using vector
#include <algorithm> // For using sort()
#include <chrono> // For measure time
using namespace std;
using namespace chrono;

int main(){
  system("clear");
  // std::vector is simillar with array.
  // Although it has extra methods like 'push_back', 'begin', 'end' and etc...
  // which is, std::vector is a "class type" array.
  vector<string> strvec;
  // vector.push_back(element) method will push an element into a vector.
  strvec.push_back("python");
  strvec.push_back("java");
  strvec.push_back("csharp");
  strvec.push_back("php");
  strvec.push_back("ruby");
  strvec.push_back("electron");
  strvec.push_back("typescript");
  strvec.push_back("shell");
  // Let's print them out before sorting it!
  // We will use a new data structure in for loop called "iterator"
  vector<string>::iterator it;
  cout << "Before sorting: " << endl;
  for(it=strvec.begin(); it!=strvec.end(); ++it){
    cout << *it << " ";
  }
  cout << endl << endl;
  // Then let's sort! All we need is this single line :D
  // sort(begin, end) is an method from <algorithm> library.
  auto start = high_resolution_clock::now(); // Start timer!
  sort(strvec.begin(), strvec.end());
  auto stop = high_resolution_clock::now(); // End timer
  // Let's print them again if they're sorted well!
  cout << "After sorting: " << endl;
  for(it=strvec.begin(); it!=strvec.end(); ++it){
    cout << *it << " ";
  }
  cout << endl << endl;
  auto duration = duration_cast<nanoseconds>(stop-start); // Get time consumed in nm
  cout << "Time used for sorting: " << duration.count() << " ns " << endl;
  return 0;
}
