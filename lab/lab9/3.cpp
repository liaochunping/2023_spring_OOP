#include <iostream>

using namespace std;

class Distance {
    friend istream& operator>>(istream& in, Distance& d);
    friend ostream& operator<<(ostream& out, const Distance& d);
    public:
	Distance() = default;
	Distance(int f, int i): feet(f), inches(i) { }
    private:
	int feet;
	int inches;
};

inline ostream& operator<<(ostream& out, const Distance& d) {
    out << "F : " << d.feet << " I : " << d.inches;
    return out;
}

inline istream& operator>>(istream& in, Distance& d) {
    in >> d.feet >> d.inches;
    return in;
}

int main() {
    Distance D1(11, 10), D2(5, 11), D3;
    cout << "Enter the value of object : " << endl;
    cin >> D3;
    cout << "First Distance : " << D1 << endl;
    cout << "Second Distance :" << D2 << endl;
    cout << "Third Distance :" << D3 << endl;
    return 0;
}
