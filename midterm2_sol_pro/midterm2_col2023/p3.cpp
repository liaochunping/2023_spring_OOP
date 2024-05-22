#include <iostream>
   
using namespace std;

class SharedArray {
private:
    int* data; // should point to dynamic memory (heap)
    int size;
    static int instances;
public:
    friend std::ostream& operator << (std::ostream& out, const SharedArray& f);
    SharedArray ():data(nullptr),size(0){
       cout << "Default Constructor is called" << endl;
       instances++;
    }
    SharedArray (int d):size(d){
       data = new int[d];
       cout << "Constructor is called" << endl;
       instances++;
    }

    // Copy size
    SharedArray (const SharedArray & source){
        instances++;
        size = source.size;
        data = source.data;
        
        cout << "Copy Constructor is called -" << "Shallow copy" << endl;
    }
    // Copy Assignment Operator
    SharedArray& operator=(const SharedArray & source){
        data = source.data;
        size = source.size;
        cout << "Copy Assignment" << endl;
        return *this;
    }

    // Move Constructor
    SharedArray (SharedArray && source) : size(source.size),data(source.data){
        instances++;
        source.data = nullptr;
        cout << "Move Constructor" << endl;
    }

    // Move Assignment Operator
    SharedArray& operator=(SharedArray && source){
        if(&source == this) return *this;
        
        size = source.size;

        delete this->data;
        this->data = source.data;
        source.data = nullptr;
        
        cout << "Move Assignment" << endl;
        return *this;
    }

    int &operator[] (const size_t index) { 
        return data[index]; 
    } 
    const int &operator[] (const size_t index) const {
        return data[index];
    }
    int getSize() const {
        return size;
    }
    // Destructor
    ~SharedArray (){
       if (instances > 1)
           cout << "Destructor is called but data still in use by other object!" << endl;
       else {
           cout << "Destructor is called and clean up is done!" << endl;
             delete[] data;
        }
        cout << "instances left: " << --instances << endl;;
    }
};

std::ostream& operator << (std::ostream& out, const SharedArray& f){ 
    for(auto i = 0; i < f.getSize(); i++)
        out << f[i] << " ";
    out << endl;
    return out; 
}

int SharedArray::instances = 0;

SharedArray create(){
      return SharedArray(5);
}

int main(){
    SharedArray m;
    cout << "before call to create()" << endl;
    m = create();
    m[0] = 5;
    cout << "m: " << m;
    const SharedArray n(m);
    m[0] = 1;
    m[2] = n[0];
    cout << "m: " << m;
    cout << "n: " << n;
    SharedArray o;
    o = m;
    cout << "o: " << o;
    SharedArray p = move(create());
    cout << "before returning from main" << endl;
    return 0; 
}