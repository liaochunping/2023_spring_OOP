#include <string>
#include <iostream>

class Rectangle {
private:
  std::string color;
  double width;
  double length;

public:
  Rectangle():width(1),length(1),color("White"){ }
  Rectangle(const std::string &s, double a, double b): color(s), width(a), length(b) { }

  void printInfo() const {std::cout << "Color: " << color << ", width: " << width << ", length: " << length <<std::endl;}
  void changeColor(std::string n) {color = n;}
  void changeWidth(double n) {width = n;}
  void changeLength(double n) {length = n;}
  bool isSquare(){
    double d = width - length;
    if( d < 0) d *= -1;
    return d < 0.0001;
  }
};

using namespace std;

int main() {
  cout << "Start of main() "<< endl;

  cout << "1. ";
  Rectangle r1("Yellow",30, 40);
  r1.printInfo();

  cout << "2. ";
  Rectangle r2(r1);
  r2.printInfo();
  cout << "3. is r2 square? " << r2.isSquare() << endl;

  cout << "4. ";
  Rectangle r3;
  r3.printInfo();

  cout << "5. ";
  r2.changeColor("Green");
  r2.changeWidth(100);
  r2.changeLength(100);
  r3 = r2;
  r3.printInfo();
  cout << "6. is r3 square? " << r3.isSquare() << endl;
  
  cout << "End of main() "<< endl;
}
