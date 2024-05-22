#ifndef SQUARE_H
#define SQUARE_H

class Square {
private:
    double side;
public:
    Square(double);

    //friend void Rectangle::convert(Square);
    friend class Rectangle;
};

#endif
