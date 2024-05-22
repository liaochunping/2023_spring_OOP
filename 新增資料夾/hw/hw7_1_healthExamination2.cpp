#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
    friend ostream &print(ostream &os, Person* p);
    
    private:
        string name;
        int age;
        double height;
        double weight;
        
    public:
        static int min;
        static int max;
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
        double get_bmi() {return weight / height / height * 10000;}
        static void set_bmi_range(int from, int to) {
            min = from;
            max = to;
        }
};

int Person::min = 0;
int Person::max = 0;

class HealthExamination {
    private:
        vector<Person*> vp;
    
    public:
        void add_person() {
            string name;
            int age;
            double height;
            double weight;        
            cin >> name >> age >> height >> weight;
            vp.push_back(new Person(name, age, height, weight));
        }
        
        vector<Person*> get_unhealthy_people() {
            vector<Person*> unhealthy;
            for(auto i : vp) {
                if(i->get_bmi() < i->min || i->get_bmi() > i->max) {
                    unhealthy.push_back(i);
                }
            }
            return unhealthy;
        }
};

ostream &print(ostream &os, Person* p) {
    os << p->name << "(" << p->age << ") have an unhealthy BMI " << p->get_bmi() << endl;
    return os;
};

int main()
{
    int num;
    cin >> num;

    HealthExamination check;

    for (int i = 0; i < num; i++)
    {
        check.add_person();
    }

    int min, max;

    cin >> min >> max;

    Person::set_bmi_range(min, max);

    vector<Person*> unhealthy = check.get_unhealthy_people();

    for (auto p : unhealthy)
    {
        print(cout, p);
    }
}