#include <iostream>

using namespace std;

class Complex {
    friend istream& operator>>(istream& stream, Complex& c);
    friend ostream& operator<<(ostream& stream, const Complex& c);
    friend bool operator>= (const Complex& c1, const Complex& c2);
    
private:
    int real, imag;
    
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    Complex & operator+(const Complex &rhs) {
        real += rhs.real;
        imag += rhs.imag;
        
        return *this;
    }
};

istream& operator>>(istream& stream, Complex& c) {
    stream >> c.real >> c.imag;
    return stream;
}

ostream& operator<<(ostream& stream, const Complex& c) {
    stream << c.real << "+" << c.imag << "i";
    return stream;
}

bool operator>= (const Complex& c1, const Complex& c2) {
    return c1.real >= c2.real;
}

int main() {
    Complex c1, c2;
    cin >> c1 >> c2;
    
    if(c1 >= c2)
        cout << c1 << " >= " << c2 << endl;
    else
        cout << c1 << " < " << c2 << endl;
        
    return 0;
}