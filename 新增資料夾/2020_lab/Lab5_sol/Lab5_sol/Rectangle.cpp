#include <iostream>
#include "Rectangle.h"
#include "Square.h"

using namespace std;

double Rectangle::area() const{
    return width * height;
}
void Rectangle::convert(Square s){
    width = s.side;
    height = s.side;
}
void Rectangle::print() const{
    cout << "width: " << this->width << ", height: " << this->height << ", area: " << this->area() << endl;
}