#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    friend ostream &print(ostream &os, Person &p);
    
    private:
        string name;
        int age;
        double height;
        double weight;
    public:
        Person(string n, int a, double h, double w) {
            name = n;
            age = a;
            height = h;
            weight = w;
        }
        string getName() {return name;}
        int getAge() {return age;}
        double getHeight() {return height;}
        double getWeight() {return weight;}
        double getBMI() {return weight / height / height * 10000;}
};

class HealthExamination {
    private:
        vector<Person> vp;
    
    public:
        void addPerson() {
            string name;
            int age;
            double height;
            double weight;        
            cin >> name >> age >> height >> weight;
            vp.push_back(Person(name, age, height, weight));
        }
        
        vector<Person> getUnhealthyPeople() {
            vector<Person> unhealthy;
            for(auto i : vp) {
                if(i.getBMI() < 18.5 || i.getBMI() > 24) {
                    unhealthy.push_back(i);
                }
            }
            return unhealthy;
        }
};


ostream &print(ostream &os, Person &p)
{
    os << p.name << "(" << p.age << ") have an unhealthy BMI " << p.getBMI() << endl;
    return os;
}

int main()
{
    int num;
    cin >> num;

    HealthExamination check;

    for (int i = 0; i < num; i++)
    {
        check.addPerson();
    }

    vector<Person> unhealthy = check.getUnhealthyPeople();

    for (auto p : unhealthy)
    {
        print(cout, p);
    }
}
