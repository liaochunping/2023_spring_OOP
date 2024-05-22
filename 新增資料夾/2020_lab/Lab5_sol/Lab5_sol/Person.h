#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person{
    private:
    std::string name;
    int age;
    
    public:
    //Person(std::string n, int a): name(n), age(a){}
    Person(std::string n, int a);
    
    //int getAge() const { return age;}
    int getAge() const;
    
    //std::string getName() const {return name; }
    std::string getName() const;
};

#endif