#include <iostream>
#define MAXVALUE 4

using namespace std;

template<class T> class Stack{
  public:
    int top;
    int size;
    T *values;
    // Constructor
    Stack(){
      // Unlike Dynamic Data Structures like Linked List,
      // Stack has to predefine the size
      size = MAXVALUE;
      values = new T[size];
      top = -1;
    }
    // Destructor
    ~Stack(){
      delete[] values;
    }
    // Pushing elements to top
    void push(T value){
      if(!isFull()){
        values[++top] = value;
      }
      else{
        cout << "Stack is full!" << endl;
      }
    }
    // Getting rid of top element
    void pop(){
      if(!empty()){
        top--;
      }
      else{
        cout << "Stack is empty." << endl;
      }
    }
    // Return top element
    T Top(){
      return (!empty()) ? values[top] : NULL;
    }
    // Callbacks
    bool empty(){
      return (top<0) ? true : false;
    }
    bool isFull(){
      return ((top+1)==size) ? true : false;
    }
};

template<typename T> ostream& operator <<(ostream &out, Stack<T> &st){
  T *temp = st.values;
  out << "┌───┐" <<endl;
  for(int i=st.top; i>-1; i--){
    out <<"  "<<temp[i]<< endl;
  }
  out << "└───┘" << endl;
  return out;
}

int main(){
  Stack<int> st;
  int choice = 0; 
  int num = 0;
  while(choice!=3){
    system("clear");
    cout << "Choose Stack Method" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Exit" << endl
         << st << endl;
    cout << "Choice: ";
    cin >> choice;
    switch(choice){
      case 1: 
        cout << "Type number to push: ";
        cin >> num;
        st.push(num);
        break;
      case 2:
        st.pop();
        break;
      case 3:
        break;
      default:
        break;
    }
  }
  return 0;
}

