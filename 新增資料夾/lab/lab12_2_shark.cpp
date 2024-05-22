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
        cout << "New Shark with age: " << age << endl;
    }
    
    Shark(const Shark& rhs) { // copy constructor
        age = rhs.age;
        cout << "Copy Shark with age: " << age << endl;
    }
    Shark & operator = (const Shark& rhs) { // copy assignment
        if(this == &rhs) return *this;
        age = rhs.age;
        cout << "Copy assign Shark with age: " << age << endl;
        return *this;
    }
    
    Shark(Shark && source) : age(source.age) { // move constructor
        cout << "Move construct Shark with age: " << age << endl;
    }
    Shark& operator=(Shark && source) { // move assignment
        age = source.age;
        cout << "Move assign Shark with age:" << age << endl;
        return *this;
    }
    
    virtual void print(ostream& out) {
        out << "Age " << age << " Shark~~ BOO!BOO!BOO!" << endl;
    }
    
    virtual ~Shark() { // destructor
        cout << "Age " << age << " Shark~~ Bye!" << endl;
    }
};

ostream& operator << (ostream& out, Shark& s) {
    s.print(out);
    return out;
}

class BabyShark : public Shark {
protected:
    int babyage = 0;

public:
    BabyShark() = default;
    BabyShark(int a) : Shark(a) {
        babyage = age;
        cout << "New BabyShark with age: " << babyage << endl;
    }
    
    BabyShark(const BabyShark& rhs) : Shark(rhs) { // sub-class copy constructor
        babyage = age;
        cout << "Copy BabyShark with age: " << babyage << endl;
    }
    BabyShark& operator=(const BabyShark& rhs) { // sub-class copy assignment
        if(this == &rhs) return *this;
        this->Shark::operator=(rhs);
        babyage = age;
        cout << "Copy assign BabyShark with age: " << babyage << endl;
        
        return *this;
    }
    
    BabyShark(BabyShark && source) : Shark(std::move(source)) { // sub-class move constructor
        babyage = age;
        cout << "Move construct BabyShark with age: " << babyage << endl;
    }
    BabyShark& operator=(BabyShark && source) { // sub-class move assignment
        static_cast<Shark &>(*this) = std::move(source);
        babyage = age;
        cout << "Move assign BabyShark with age:" << babyage << endl;
        return *this;
    }
    
    void print(ostream& out) override {
        this->Shark::print(out);
        out << "Age " << babyage << " BabyShark~~ DOO!DOO!DOO!" << endl;
    }
    
    ~BabyShark() { // sub-class destructor
        cout << "Age " << babyage << " BabyShark~~ Bye!" << endl;
    }
};


BabyShark create(int age) {
    return BabyShark(age); // rvalue
}

int main() {
    BabyShark shark1(20);
    BabyShark shark2;
    shark2 = create(6);
    Shark* shark3 = new BabyShark(shark1);
    BabyShark shark4;
    shark4 = shark2;
    vector<BabyShark> vec;
    vec.push_back(BabyShark(35));
    cout << shark1 << shark2 << *shark3 << shark4 << vec[0];
    delete shark3;

    return 0;
}