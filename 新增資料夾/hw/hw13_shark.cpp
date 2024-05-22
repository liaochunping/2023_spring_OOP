#include <iostream>
#include <vector>

using namespace std;

class Shark {
protected:
    int age = 0;

public:
    Shark() = default;
    Shark(int a) {
        age = a;
    }
    Shark(const Shark& rhs) { // copy constructor
        age = rhs.age;
    }
    Shark & operator = (const Shark& rhs) { // copy assignment
        if(this == &rhs) return *this;
        age = rhs.age;
        return *this;
    }
    Shark(Shark && source) : age(source.age) {} // move constructor
    Shark& operator=(Shark && source) { // move assignment
        age = source.age;
        return *this;
    }
    virtual ~Shark() {} // destructor
    
    virtual void print(ostream& out) {}
};

ostream& operator << (ostream& out, Shark& s) {
    s.print(out);
    return out;
}

class BabyShark : public Shark {
public:
    BabyShark() {
        cout << "New BabyShark with age: " << age << endl;
    }
    BabyShark(int a) : Shark(a) {
        cout << "New BabyShark with age: " << age << endl;
    }
    BabyShark(const BabyShark& rhs) : Shark(rhs) { // sub-class copy constructor
        cout << "Copy BabyShark with age: " << age << endl;
    }
    BabyShark& operator=(const BabyShark& rhs) { // sub-class copy assignment
        if(this == &rhs) return *this;
        this->Shark::operator=(rhs);
        cout << "Copy assign BabyShark with age: " << age << endl;
        
        return *this;
    }
    BabyShark(BabyShark && source) : Shark(std::move(source)) { // sub-class move constructor
        cout << "Move construct BabyShark with age: " << age << endl;
    }
    BabyShark& operator=(BabyShark && source) { // sub-class move assignment
        static_cast<Shark &>(*this) = std::move(source);
        cout << "Move assign BabyShark with age: " << age << endl;
        return *this;
    }
    ~BabyShark() {
        cout << "Bye! BabyShark~~" << endl;
    }
    
    void print(ostream& out) override {
        out << "BabySharkdoo doo doo doo doo doo" << endl;
    }
};

class DaddyShark : public Shark {
public:
    DaddyShark() {
        cout << "New DaddyShark with age: " << age << endl;
    }
    DaddyShark(int a) : Shark(a) {
        cout << "New DaddyShark with age: " << age << endl;
    }
    DaddyShark(const DaddyShark& rhs) : Shark(rhs) { // sub-class copy constructor
        cout << "Copy DaddyShark with age: " << age << endl;
    }
    DaddyShark& operator=(const DaddyShark& rhs) { // sub-class copy assignment
        if(this == &rhs) return *this;
        this->Shark::operator=(rhs);
        cout << "Copy assign DaddyShark with age: " << age << endl;
        
        return *this;
    }
    DaddyShark(DaddyShark && source) : Shark(std::move(source)) { // sub-class move constructor
        cout << "Move construct DaddyShark with age: " << age << endl;
    }
    DaddyShark& operator=(DaddyShark && source) { // sub-class move assignment
        static_cast<Shark &>(*this) = std::move(source);
        cout << "Move assign DaddyShark with age: " << age << endl;
        return *this;
    }
    ~DaddyShark() {
        cout << "Bye! DaddyShark~~" << endl;
    }
    
    void print(ostream& out) override {
        out << "DaddySharktoo too too too too too" << endl;
    }
};

class MommyShark : public Shark {
public:
    MommyShark() {
        cout << "New MommyShark with age: " << age << endl;
    }
    MommyShark(int a) : Shark(a) {
        cout << "New MommyShark with age: " << age << endl;
    }
    MommyShark(const MommyShark& rhs) : Shark(rhs) { // sub-class copy constructor
        cout << "Copy MommyShark with age: " << age << endl;
    }
    MommyShark& operator=(const MommyShark& rhs) { // sub-class copy assignment
        if(this == &rhs) return *this;
        this->Shark::operator=(rhs);
        cout << "Copy assign MommyShark with age: " << age << endl;
        
        return *this;
    }
    MommyShark(MommyShark && source) : Shark(std::move(source)) { // sub-class move constructor
        cout << "Move construct MommyShark with age: " << age << endl;
    }
    MommyShark& operator=(MommyShark && source) { // sub-class move assignment
        static_cast<Shark &>(*this) = std::move(source);
        cout << "Move assign MommyShark with age: " << age << endl;
        return *this;
    }
    ~MommyShark() {
        cout << "Bye! MommyShark~~" << endl;
    }
    
    void print(ostream& out) override {
        out << "MommySharkboo boo boo boo boo boo" << endl;
    }
};

BabyShark create(int age) {
    return BabyShark(age);
}

int main() {
    vector<Shark*> vec1;

    MommyShark shark1(20);
    vec1.push_back(&shark1);

    BabyShark shark2;
    shark2 = create(6);
    vec1.push_back(&shark2);

    Shark* shark3 = new MommyShark(shark1);
    vec1.push_back(shark3);

    BabyShark shark4;
    shark4 = shark2;
    vec1.push_back(&shark4);

    DaddyShark shark5(30);
    vec1.push_back(&shark5);

    vector<DaddyShark> vec2;
    vec2.push_back(DaddyShark(35));

    for (auto s : vec1)
        cout << *s;

    delete shark3;

    for (auto& s : vec2)
        cout << s;

    return 0;
}