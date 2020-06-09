#include <iostream>
#include <string>
using namespace std;

class Shape {
  protected:
    int width, height;
      
  public:
    Shape( int a = 0, int b = 0){
      width = a;
      height = b;
    }
    void area() {
      cout << "Parent class!" << endl;
    }
};

class Rectangle: public Shape {
  public:
    Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      
    void area(){ 
      int area = width*height;
      cout << "Rectangle class area : " << area << endl;
    } 
};

class Triangle: public Shape {
  public:
    Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
    void area (){ 
      int area = width*height*0.5;
      cout << "Triangle class area : " << area << endl;
    }
};

int main(){
  Shape *shape;
  Rectangle rec(10, 7);
  Triangle tri(10, 5);

  // Polymorphism!
  shape = &rec;
  shape->area();
  shape = &tri;
  shape->area();
  
  // Polymorphis is useful especially when you want to first use parent's method,
  // and you want to switch to child's method.

  return 0;
}
