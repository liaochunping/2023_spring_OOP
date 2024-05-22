#include <iostream>

using namespace std;

template<class T>
class Size {
    private:
        T t;
    public:
        // constructor
        Size(T tt) {
            t = tt;
            cout << "size of " << t << " is " << sizeof(t) << " byte";
            if(sizeof(t) == 1) cout << "." << endl;
            else cout << "s." << endl;
        }
};


int main() {
    Size<char> p('a');
    Size<int> q(1);
    Size<float> r(3.14);
    
    return 0;
}