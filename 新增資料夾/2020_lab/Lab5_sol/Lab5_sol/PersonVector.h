#ifndef PERSONVECTOR_H
#define PERSONVECTOR_H

#include "Person.h"
#include <vector>

class PersonVector{
    private:
    std::vector<Person> persons;
    
    public:
    void addPersons();
    void displayPersons();
};

#endif