#include <iostream>

using namespace std;

class Square {
    private:
        double side;
  
    public:
        friend class Rectangle;
        Square(int s) {
            side = s;
        }
};

class Rectangle {
    // friend Square;
    
    private:
      	double width;
      	double height;

    public:
        double area() {
            return width * height;
        }
        void convert(Square sqr) {
            width = sqr.side;
            height = sqr.side;
        }
        void print() {
            cout << "width: " << width << ", height: " << height << ", area: " << area();
        }
};


int main () {
    int side;
    cin >> side;

    Rectangle rect; 
    Square sqr(side); 
    rect.convert(sqr);

    rect.print();

    return 0; 
}


