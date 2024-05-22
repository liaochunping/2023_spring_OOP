#include <iostream>

using namespace std;

class Vec {
private:    
    // int* v[5] = {new int(0), new int(1), new int(2), new int(3), new int(4)};
    int arr[5] = {0, 1, 2, 3, 4};
    int* v = arr;
    // int* v = {0, 1, 2, 3, 4}; // pointer to the array of int
    int n = 5; // length
    
public:
    // Default Constructor
    Vec() = default;
    
    // Copy Constructor
    Vec(const Vec &rhs): v(rhs.v), n(rhs.n) {}
    
    // Assignment Operator
    Vec & operator=(const Vec &rhs) {
        if(this == &rhs) return *this;
        
        v = rhs.v;
        n = rhs.n;
        
        return *this;
    };
    
    void show(string s) {
        cout << s << ": ";
        for(int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
    // Destructor
    ~Vec() {
        // delete v;
        cout << "destructor" << endl;
    }
    
};

int main() {
    Vec v;
    v.show("v1");

    {
        Vec v2(v);
        v2.show("v2");
    }

    {
        Vec v3;
        v3 = v;
        v3.show("v3"); 
    }

    v = v;

    v.show("after v = v");
}