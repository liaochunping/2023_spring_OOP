#ifndef RECTANGLE_H
#define RECTANGLE_H

class Square;

class Rectangle{
private:
    double width;
    double height;
    
public:
    double area() const;
    void convert(Square);
    void print() const;
};

#endif