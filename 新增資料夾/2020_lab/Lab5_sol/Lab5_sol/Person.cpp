#include "Person.h"

Person::Person(std::string n, int a): name(n), age(a){}
int Person::getAge() const { return age;}
std::string Person::getName() const { return name; }

