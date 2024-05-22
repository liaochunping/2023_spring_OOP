#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class Shape { // ABC
public:
    Shape() {}
    virtual void printArea() = 0;
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
    
    void printArea() {
        cout << len*wid;
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
    
    void printArea() {
        cout << (rad*rad*3.1415);
    }
    string getClassName() {
        return "Circle";
    }
};


class ShapeGroup : public Shape {
protected:
    vector<Shape*> elems;
public:
    ShapeGroup() = default;
    
    void printArea() {
        
    }
    string getClassName() {
        return "ShapeGroup";
    }
    
    virtual void insert(Shape* s) {
        elems.push_back(s);
    }
    
    // copy constructor
    ShapeGroup(const ShapeGroup& rhs) {
        for(int i = 0; i < rhs.elems.size(); i++) {
            this->insert(rhs.elems[i]);
        }
        cout << "ShapeGroup::Copy Constructor " << endl;
    }
    
    // destructor
    ~ShapeGroup() {
        cout << "ShapeGroup::Destructor " << endl;
    }
};

class ShapeGroupID : public ShapeGroup {
protected:
    vector<int> IDs;
public:
    ShapeGroupID() = default;
    
    void printArea() {
        for(int i = 0; i < elems.size(); i++) {
            cout << elems[i]->getClassName() << " of id " << IDs[i] 
                << "\'s area: " << endl;
            elems[i]->printArea();
            cout << endl;
        }
    }
    string getClassName() {
        return "****ShapeGroupID";
    }
    
    virtual void insert(Shape* s) {
        ShapeGroup::insert(s);
        IDs.push_back(rand() % 100);
    }

    void insert(ShapeGroupID& sgid) {
        elems.push_back(&sgid);
    }
    
    // copy constructor
    ShapeGroupID(const ShapeGroupID& rhs) : ShapeGroup(rhs) {
        for(int i = 0; i < elems.size(); i++) {
            this->IDs.push_back(rhs.IDs[i]);
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

    Rectangle* r1 = new Rectangle(10,20);
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
    sgID3.insert(&sgID2);

    sgID3.printArea();

    delete r1; delete c1; delete s1; delete c2; delete s2;
    delete c3; delete s3;

    return 0;
}