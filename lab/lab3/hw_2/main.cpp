#include <iostream>
using namespace std;
 

int main() {
 

    int n, reversed_number = 0, remain;
    cin >> n;
    while(n != 0) {
    remain = n % 10;
    reversed_number = reversed_number * 10 + remain;
    n /= 10;
    }
    cout << reversed_number;
     
    
    return 0;
}