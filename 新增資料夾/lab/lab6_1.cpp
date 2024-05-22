#include <iostream>
#include <vector>
using namespace std;
// Do not change class name

class Person{
    private:
        string name;
        int age;
    
    public:
        Person(string name, int age) {
            this->name = name;
            this->age = age;
        }
        string getName() {
            return name;
        }
        int getAge() {
            return age;
        }
};

class PersonVector{
    private:
        vector<Person> persons;
  
    public:
        void addPersons() {
            int num;
            cin >> num;
            string name;
            int age;
            for(int i = 0; i < num; i++) {
                cin >> name >> age;
                persons.push_back(Person(name, age));
            }
        }
        void displayPersons() {
            for(int i = 0; i < persons.size(); i++) {
                cout << persons[i].getName() << " " << persons[i].getAge() << endl;
            }
        }
};


int main(){ 
    PersonVector pv; 
    pv.addPersons(); 
    pv.displayPersons();
    return 0;
}
