#include <iostream>

using namespace std;

template<class T>
class TypeCounter {
    public:
        static int count;
        
        TypeCounter() {
            count ++;
        }
    
};

template<> int TypeCounter<int>::count = 0;
template<> int TypeCounter<double>::count = 0;
template<> int TypeCounter<string>::count = 0;

int main() {
    TypeCounter<int> a;  
    TypeCounter<int> b;  
    TypeCounter<int> c;  
    TypeCounter<double> d;  
    TypeCounter<double> e;  
    TypeCounter<string> f;  
    cout << TypeCounter<int>::count   << endl;  
    cout << TypeCounter<double>::count << endl; 
    cout << TypeCounter<string>::count << endl; 
    
    return 0;
}
