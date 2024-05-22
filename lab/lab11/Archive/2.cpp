#include <iostream>
#include <vector>

using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(const string& animalName) : name(animalName) {}

    virtual void sound() {
        cout << "The animal makes a sound.\n";
    }
};

class Cat : public Animal {
public:
    Cat(const string& catName) : Animal(catName) {}

    void sound() override {
        cout << "The cat meows.\n";
    }
};

class Dog : public Animal {
public:
    Dog(const string& dogName) : Animal(dogName) {}

    void sound() override {
        cout << "The dog barks.\n";
    }
};

class Zoo {
private:
    vector<Animal*> animals;

public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void makeAllSounds() {
        for (Animal* animal : animals) {
            animal->sound();
        }
    }
};

int main() {
    Zoo zoo;

    Cat cat("Oscar");
    Dog dog("Buddy");

    zoo.addAnimal(&cat);
    zoo.addAnimal(&dog);

    zoo.makeAllSounds();

    return 0;
}