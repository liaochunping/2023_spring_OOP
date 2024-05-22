#include <iostream>
#include <ctime> // random seed
#include <cstdlib> //random pick
#include <vector>

using namespace std;

class DoubleArray {
protected:
    double* raw_data = nullptr;
    unsigned array_size = 0;
    
public:
    DoubleArray() = default;
    DoubleArray(unsigned s, double val) {
        array_size = s;
        raw_data = new double[array_size];
        for(unsigned i = 0; i < array_size; i++) {
            raw_data[i] = val;
        }
    }
    
    DoubleArray(const DoubleArray& rhs) { // copy constructor
        // deep copy
        array_size = rhs.array_size;
        raw_data = new double[array_size];
        for(unsigned i = 0; i < array_size; i++) {
            raw_data[i] = rhs.raw_data[i];
        }
    }
    DoubleArray& operator=(const DoubleArray& rhs) { // copy assignment
        if(this == &rhs) return *this;
        if(raw_data != nullptr) delete[] raw_data;
        // deep copy
        array_size = rhs.array_size;
        raw_data = new double[array_size];
        for(unsigned i = 0; i < array_size; i++) {
            raw_data[i] = rhs.raw_data[i];
        }
        return *this;
    }
    
    virtual void print(ostream& os) const {
        os << "array size: " << array_size << ", {";
        if(array_size > 0) {
            for(unsigned i = 0 ; i < array_size-1; i++) {
                os << raw_data[i] << ", ";
            }
            os << raw_data[array_size-1] << "}" << endl;
        }
        else os << " }" << endl;
    }
    
    virtual ~DoubleArray() {
        if(raw_data != nullptr) {
            delete[] raw_data;
            cout << "delete[] in destructor!" << endl;
        }
    }
};

ostream& operator << (ostream& os, const DoubleArray& da) {
    da.print(os);
    return os;
}

class DoubleArrayID : public DoubleArray {
protected:
    int* randID = nullptr;
    
public:
    DoubleArrayID() = default;
    DoubleArrayID(unsigned s, double val) : DoubleArray(s, val) {
        randID = new int[array_size];
        srand(time(0)); // random seed
        for(unsigned i = 0; i < array_size; i++) {
            // randID[i] = rand()%100;
            randID[i] = raw_data[i]*433;
        }
    }
    
    DoubleArrayID(const DoubleArrayID& rhs) : DoubleArray(rhs) { // sub-class copy constructor
        randID = new int[array_size];
        for(unsigned i = 0; i < array_size; i++) {
            randID[i] = rhs.randID[i];
        }
    }
    DoubleArrayID& operator=(const DoubleArrayID& rhs) { // sub-class copy assignment
        if(this == &rhs) return *this;
        this->DoubleArray::operator=(rhs); // copy base portion
        if(randID != nullptr) delete[] randID;
        // deep copy
        randID = new int[array_size];
        for(unsigned i = 0; i < array_size; i++) {
            randID[i] = rhs.randID[i];
        }
        return *this;
    }
    
    void print(ostream& os) const override {
        DoubleArray::print(os);
        os << ":: {";
        if(array_size > 0){
            for (unsigned index = 0; index < array_size - 1; ++index){
                os << randID[index] << ", ";
            }
            os << randID[array_size - 1] << "}" << endl;
        }
        else os << " }" << endl;
    }
    
    ~DoubleArrayID() override {
        if(randID != nullptr) {
            delete randID;
            cout << "delete[] in subclass destructor" << endl;
        }
    }
};


int main() {
    DoubleArrayID dar0;
    DoubleArrayID dar1(3, 0.1);
    DoubleArrayID dar2(6, 0.5);
    DoubleArray *dar3 = new DoubleArrayID(dar1);
    DoubleArrayID dar4;
    dar4 = dar2;
    cout << dar0 << dar1 << dar2 << *dar3 << dar4;

    delete dar3;

    return 0;
}

