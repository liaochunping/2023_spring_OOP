#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual string speak() {
        return "I am animal.";
    }
};

class Cow : public Animal {
public:
    virtual string speak() override {
        return "I am cow.";
    }
};

class Dog : public Animal {
public:
    virtual string speak() override {
        return "I am dog.";
    }
};

class Cat : public Animal {
public:
    virtual string speak() override {
        return "I am cat.";
    }
};

ostream& operator << (ostream& out, Animal* a) {
    out << a->speak();
    return out;
}


int main() {
    Animal* cow = new Cow ;
    cout << cow << endl ;
    delete cow;
    
    Animal* dog = new Dog ;
    cout << dog << endl ;
    delete dog;
    
    Animal* cat = new Cat ;
    cout << cat << endl ;
    delete cat;
    
    return 0;
}