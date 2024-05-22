#include "PersonVector.h"
#include <iostream>
#include <string>

void PersonVector::addPersons(){
        std::cout << "How many person(s) to add?";
        int n;
        std::cin >> n;
        
        for(int i = 0; i != n; ++i){
            int a;
            std::string na;
            std::cout << i << " Person to add:";
            std::cin >> na >> a;
            persons.push_back(Person(na, a));
        }
    }
void PersonVector::displayPersons(){
	for(int i = 0; i != persons.size(); ++i){
		std:: cout << persons[i].getName() << "\t" << persons[i].getAge() << std::endl;
	}
}