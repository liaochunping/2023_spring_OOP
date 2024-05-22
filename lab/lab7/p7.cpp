#include <iostream>
using namespace std ;

int call_count() {
    static int count = 0;
    count++;
    return count;
}

int main() {
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    cout << "Call count: " << call_count() << endl;
    return 0;
}
