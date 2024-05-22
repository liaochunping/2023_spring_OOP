#include <iostream>
using namespace std;

class OOPClass {
    private:
        static int count;
  
    public:
        static void printCount() {
            cout << count/2.0 << " " << count;
        }
        
        // Constructor
        OOPClass() {
            count++;
        }
};

int OOPClass::count = 0;

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        OOPClass a;
    }
    OOPClass::printCount();
}
