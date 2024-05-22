#include <iostream>

using namespace std;

class Fraction {
    friend istream& operator >> (istream& in, Fraction& f);
    friend ostream& operator << (ostream& out, Fraction& f);

protected:
    int numer, denom;
    virtual string print() {
        return to_string(numer)+'/'+to_string(denom);
    }

public:
    Fraction() = default;
    Fraction(int n, int d) {
        numer = n;
        denom = d;
    }
};

istream& operator >> (istream& in, Fraction& f) {
    int n, d;
    char slash;
    in >> n >> slash >> d;
    f = Fraction(n, d);
    return in;
}

ostream& operator << (ostream& out, Fraction& f) {
    out << f.print();
    return out;
}

class RFraction : public Fraction {
private:
    int gcd(int a, int b) {
        // make sure a < b
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        
        int temp;
        while(a != 0) {
            temp = a;
            a = b % a;
            b = temp;
        }
        return abs(b);
    }
    
    void reduce(int& a, int& b) {
        int g = gcd(a, b);
        a /= g;
        b /= g;
    }
    
    string print() override {
        reduce(numer, denom);
        return to_string(numer)+'/'+to_string(denom);
    }
    
public:
    RFraction(): Fraction() {}
    RFraction(int n, int d): Fraction(n, d) {
        // cout << "rf constructor: (n, d)" << endl;
        reduce(numer, denom);
    }
};


int main() {
    Fraction f1(2, 4);
    Fraction f2;

    cin >> f2;
    cout << "Fractions are: ";
    cout << f1 << ", ";
    cout << f2 << endl;

    RFraction rf1(2, 4);
    RFraction rf2;

    cin >> rf2;
    cout << "Reduced fractions are: ";
    cout << rf1 << ", ";
    cout << rf2 << endl;

    return 0;
}
