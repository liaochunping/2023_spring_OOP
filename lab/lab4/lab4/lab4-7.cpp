#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if(n <= 0) return false;
    else if(n == 1) return true;
    else if(n % 3 != 0) return false;
    else return isPowerOfThree(n/3);
}

int main() {
    int n = 1;
    cout << isPowerOfThree(n);
    return 0;
}