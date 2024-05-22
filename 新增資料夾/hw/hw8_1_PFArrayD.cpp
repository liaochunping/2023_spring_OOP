#include <iostream>
#include <vector>

using namespace std;

class PFArrayD {

    friend ostream &print(ostream &os, const PFArrayD& pfa);

private:
    vector<double> vec;

public:
    // default constructor
    PFArrayD() {
        int cap = 50;
        vec.reserve(cap);
        cout << "PFArrayD()" << endl;
        cout << "Allocate " << cap << " doubles" << endl;
    }
    // constructor with unsigned argument
    PFArrayD(unsigned cap) {
        vec.reserve(cap);
        cout << "PFArrayD(unsigned)" << endl;
        cout << "Allocate " << cap << " doubles" << endl;
    }
    // copy constructor
    PFArrayD(const PFArrayD &rhs): vec(rhs.vec) {
        vec.reserve(rhs.vec.capacity());
        cout << "PFArrayD(const PFArrayD&)" << endl;
        cout << "Allocate " << vec.capacity() << " doubles" << endl;
    }
    // copy assignment operator
    PFArrayD & operator=(const PFArrayD &rhs) {
        if(this == &rhs) return *this;
    
        cout << "operator = (const PFArrayD&)" << endl;
        cout << "Release " << vec.capacity() << " doubles" << endl;
        vec = rhs.vec;
        vec.reserve(rhs.vec.capacity());
        cout << "Allocate " << vec.capacity() << " doubles" << endl;
        
        return *this;
    }
    // destructor
    ~PFArrayD() {
        cout << "~PFArrayD()" << endl;
        cout << "Release " << vec.capacity() << " doubles" << endl;
    }
    
    void addElement(double ele) {
        vec.push_back(ele);
    }
    int getCapacity() {
        return vec.capacity();
    }
    int getNumberUsed() {
        return vec.size();
    }
};

ostream &print(ostream &os, const PFArrayD& pfa) {
    os << "Elements in array: ";
    for(auto i: pfa.vec) {
        os << i << " ";
    }
    os << endl;
    return os;
}


int main() {
    PFArrayD pfa1;
    pfa1.addElement(1.0);
    pfa1.addElement(2.0);
    cout << "Capacity for pfa1: " << pfa1.getCapacity() << endl;
    cout << "Elements used in pfa1: " << pfa1.getNumberUsed() << endl;
    
    cout << "----------------" << endl;
    
    PFArrayD pfa2(30);
    pfa2.addElement(3.0);
    cout << "Capacity for pfa2: " << pfa2.getCapacity() << endl;
    cout << "Elements used in pfa2: " << pfa2.getNumberUsed() << endl;
    
    cout << "----------------" << endl;
    
    PFArrayD pfa3 = pfa2;
    cout << "Capacity for pfa3: " << pfa3.getCapacity() << endl;
    cout << "Elements used in pfa3: " << pfa3.getNumberUsed() << endl;
    
    cout << "----------------" << endl;
    
    pfa3 = pfa1;
    cout << "Capacity for pfa3: " << pfa3.getCapacity() << endl;
    cout << "Elements used in pfa3: " << pfa3.getNumberUsed() << endl;
    
    cout << "----------------" << endl;
    
    print(cout, pfa3);
    return 0;
}