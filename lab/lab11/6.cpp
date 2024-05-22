#include <iostream>
#include <vector>

using namespace std;

class Shark {
protected:
    int age = 0;

public:
    Shark() = default;
    Shark(int a) : age(a) {
        cout << "New Shark with age: " << age << endl;
    }
    
    virtual void print(ostream& out) {
        out << "Age " << age << " Shark~~ BOO!BOO!BOO!" << endl;
    }
    
    virtual ~Shark() {
        cout << "Age " << age << " Shark~~ Bye!" << endl;
    }
};

ostream& operator<<(ostream& out, Shark& s) {
    s.print(out);
    return out;
}

class BabyShark : public Shark {
protected:
    int babyage = 0;

public:
    BabyShark() = default;
    BabyShark(int a) : Shark(a),  babyage(a) {
        cout << "New BabyShark with age: " << babyage << endl;
    }
    
    void print(ostream& out) override {
        this->Shark::print(out);
        out << "Age " << babyage << " BabyShark~~ DOO!DOO!DOO!" << endl;
    }
    
    ~BabyShark() {
        cout << "Age " << babyage << " BabyShark~~ Bye!" << endl;
    }
};


int main() {
    cout << "---------a-----------" << endl;
    BabyShark shark1(20);
    BabyShark shark2(6);
    vector<BabyShark> vec;
    vec.push_back(BabyShark(35));
    cout << "---------b-----------" << endl;
    cout << shark1 << shark2   << vec[0];
    cout << "---------c-----------" << endl;

    return 0;
}