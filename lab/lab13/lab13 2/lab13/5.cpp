#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Shape { // ABC
public:
    Shape() {}
    virtual void getArea() = 0;
    virtual string getClassName() = 0;
};

class Rectangle : public Shape {
protected:
    double len, wid;
public:
    Rectangle() = default;
    Rectangle(double l, double w) {
        len = l;
        wid = w;
    }
    
    void getArea() {
        cout << len * wid;
    }
    string getClassName() {
        return "Rectangle";
    }
};

class Square : public Rectangle {
public:
    Square() = default;
    Square(int l) {
        len = l;
        wid = l;
    }
    
    string getClassName() {
        return "Square";
    }
};

class Circle : public Shape {
protected:
    double rad;
public:
    Circle() = default;
    Circle(double r) {
        rad = r;
    }
    
    void getArea() {
        cout << (rad * rad * 3.1415);
    }
    string getClassName() {
        return "Circle";
    }
};

class ShapeGroupID : public Shape {
protected:
    vector<Shape*> elems;
    vector<int> IDs;
public:
    ShapeGroupID() = default;
    
    void getArea() {
        for(int i = 0; i < elems.size(); i++) {
            cout << elems[i]->getClassName() << " of id " << IDs[i] 
                << "\'s area: " << endl;
            elems[i]->getArea();
            cout << endl;
        }
    }
    string getClassName() {
        return "****ShapeGroupID";
    }
    
    void insert(Shape* s) {
        elems.push_back(s);
        IDs.push_back(rand() % 100);
    }

    void insert(ShapeGroupID& sgid) {
        for(int i = 0; i < sgid.elems.size(); i++) {
            elems.push_back(sgid.elems[i]);
            IDs.push_back(sgid.IDs[i]);
        }
    }
    
    // copy constructor
    ShapeGroupID(const ShapeGroupID& rhs) {
        for(int i = 0; i < rhs.elems.size(); i++) {
            this->insert(rhs.elems[i]);
        }
        cout << "ShapeGroupID::Copy Constructor " << endl;
    }
    
    // destructor
    ~ShapeGroupID() {
        cout << "ShapeGroupID::Destructor " << endl;
    }
};

int main() {
    srand(42);
    ShapeGroupID sgID;

    Rectangle* r1 = new Rectangle(10, 20);
    Circle* c1 = new Circle(10);
    Square* s1 = new Square(10);
    sgID.insert(r1);
    sgID.insert(c1);
    sgID.insert(s1);

    ShapeGroupID sgID2;
    Circle* c2 = new Circle(5);
    Square* s2 = new Square(5);
    sgID2.insert(c2);
    sgID2.insert(s2);

    ShapeGroupID sgID3(sgID);
    Circle* c3 = new Circle(20);
    Square* s3 = new Square(20);
    sgID3.insert(c3);
    sgID3.insert(s3);
    sgID3.insert(sgID2);

    sgID3.getArea();

    delete r1;
    delete c1;
    delete s1;
    delete c2;
    delete s2;
    delete c3;
    delete s3;

    return 0;
}
