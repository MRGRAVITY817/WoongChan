#include <iostream>
#define MAXVALUE 10

using namespace std;

template<class T> class Queue {
  public:
    int front;
    int rear;
    int size;
    T *values;

    Queue(){
      size = MAXVALUE;
      values = new T[size];
      front = 0;
      rear = 0;
    }
    ~Queue() {
      delete[] values;
    }

    void push(T value){
      if(!isFull()){
        values[rear] = value;
        rear = (rear+1)%size;
      }
      else
        cout << "Queue is full" << endl;
    }
    void pop() {
      if(!empty())
        front = (front+1)%size;
      else
        cout << "Queue is empty" << endl;
    }
    bool empty(){
      return (rear==front) ? true : false;
    }
    bool isFull(){
      return ((rear+1)%size==front) ? true : false;
    }
};

template<typename T> ostream& operator <<(ostream &out, Queue<T> &q){
  T *temp = q.values;
  out << "front [ ";
  for(int i=q.front; i<q.rear; i++){
    out << temp[i];
    if(i < q.rear-1)
      out << " | ";
  }
  out << " ] rear" << endl;
  return out;
}

int main(){
  Queue<int> q;
  int choice = 0; 
  int num = 0;
  while(choice!=3){
    system("clear");
    cout << "Choose Queue Method" << endl
         << "1. Push" << endl
         << "2. Pop" << endl
         << "3. Exit" << endl
         << q << endl;
    cout << "Choice: ";
    cin >> choice;
    switch(choice){
      case 1: 
        cout << "Type number to push: ";
        cin >> num;
        q.push(num);
        break;
      case 2:
        q.pop();
        break;
      case 3:
        break;
      default:
        break;
    }
  }
  return 0;
}
