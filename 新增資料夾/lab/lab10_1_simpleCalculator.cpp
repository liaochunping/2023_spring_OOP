#include <iostream>

using namespace std;

template<class T>
class Calculator {
    private:
        T a, b;
    public:
        Calculator(T a, T b) {
            this->a = a;
            this->b = b;
        }
        
        void displayResult() {
            cout << "Numbers: " << a << " and " << b << "." << endl;
            cout << a << " + " << b << " = " << a+b << endl;
            cout << a << " - " << b << " = " << a-b << endl;
            cout << a << " * " << b << " = " << a*b << endl;
            cout << a << " / " << b << " = " << a/b << endl;
        }
};


int main() {

    Calculator<int> intCalc(20, 33);
    Calculator<float> floatCalc(3.24, 1.11);
    
    cout << "Int results:" << endl;
    intCalc.displayResult();
    
    cout << endl;
    
    cout << "Float results:" << endl;
    floatCalc.displayResult();
    
    return 0;
}