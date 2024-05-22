#include <iostream>
#include <set>
#include <cmath>

using namespace std;

class VecFour {
    friend std::ostream& operator<<(ostream& stream, const VecFour& vf);
    friend std::istream& operator>>(istream& stream, VecFour& vf);
    friend const VecFour operator*(const double& mult, const VecFour& vf);
    friend bool operator<(const VecFour& a, const VecFour& b);

private:
    double x, y, z, h;
    
public:
    // constructor with 4 parameters
    VecFour(const double& x = 0, const double& y = 0, const double& z = 0, const double& h = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->h = h;
    }
    
    // assignment operator
    VecFour& operator=(const VecFour& rhs) {
        if(this == &rhs) return *this;
        x = rhs.x;
        y = rhs.y;
        z = rhs.z;
        h = rhs.h;
        
        return *this;
    }
    
    // overload operator '*='
    VecFour& operator*=(const VecFour &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        h *= rhs.h;
        
        return *this;
    }
};

// cout << a
inline std::ostream& operator<<(ostream& stream, const VecFour& vf) {
    stream << "(" << vf.x << ", " << vf.y << ", " << vf.z << ", " << vf.h << ")";
    return stream;
}

// cin >> a
inline std::istream& operator>>(istream& stream, VecFour& vf) {
    stream >> vf.x >> vf.y >> vf.z >> vf.h;
    return stream;
}

// 2.5*a
inline const VecFour operator*(const double& mult, const VecFour& vf) {
    return VecFour(mult*vf.x, mult*vf.y, mult*vf.z, mult*vf.h);
}

// a < b
inline bool operator<(const VecFour& a, const VecFour& b) {
    double da, db = 0;
    da = pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2) + pow(a.h, 2);
    db = pow(b.x, 2) + pow(b.y, 2) + pow(b.z, 2) + pow(b.h, 2);
    return da < db;
}

int main() {
    VecFour a = VecFour(1.0,1.0,2.0,2.0);
    cout << "The vector \'a\' is: " << a << endl;

    VecFour b;
    cin >> b;
    cout << "The vector you input is: " << b << endl;

    VecFour c = 2.5*a;
    cout << "The vector \'c\' is : " << c << endl;

    c *= a;
    cout << "The vector \'c\' changes to : " << c << endl;

    VecFour d;
    cout << "The vector \'d\' is : " << d << endl;

    set<VecFour> coll{a, b, c, d};
    for (const auto& e : coll)
        cout << e << " ";

    cout << endl;
    return 0;
}