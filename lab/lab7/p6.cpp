#include <iostream>
#include <memory>
#include <string>

class Person {
private:
    std::string name;

public:
    Person(const std::string& n) : name(n) {}
    void introduce() const {
        std::cout << "Hi, my name is " << name << std::endl;
    }
};

std::unique_ptr<Person> createPerson(const std::string& name) {
    return std::make_unique<Person>(name);
}

int main() {
    std::unique_ptr<Person> p = createPerson("Albert");
    p->introduce();

    return 0;
}
