#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Shape {
public:
    Shape() {}
    virtual double getArea() = 0;
    virtual string getClassName() = 0;
};

ostream& operator << (ostream& os, Shape* s) {
    os << s->getClassName() << "\'s area is " << s->getArea() << endl;
    return os;
}

class Rectangle : public Shape {
private:
    double len, wid;
public:
    Rectangle() = default;
    Rectangle(double l, double w) {
        len = l;
        wid = w;
    }
    
    double getArea() {
        return len * wid;
    }
    string getClassName() {
        return "Rectangle";
    }
};

class Circle : public Shape {
private:
    double rad;
public:
    Circle() = default;
    Circle(double r) {
        rad = r;
    }
    
    double getArea() {
        return rad * rad * 3.1415;
    }
    string getClassName() {
        return "Circle";
    }
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle() = default;
    Triangle(double aa, double bb, double cc) {
        a = aa;
        b = bb;
        c = cc;
    }
    
    double getArea() {
        double s = 0.5 * (a + b + c);
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
    string getClassName() {
        return "Triangle";
    }
};


int main() {
    vector<Shape*> vs;
    Rectangle r(10,20);
    Circle c(10);
    Triangle t(18,30,24);
    vs.push_back(&r);
    vs.push_back(&c);
    vs.push_back(&t);
    for(auto s : vs)
        cout << s;
    return 0; 
}
