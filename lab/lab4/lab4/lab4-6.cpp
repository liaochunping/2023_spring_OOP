#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int num1 = 12;
    int num2 = 18;
    int result = lcm(num1, num2);
    cout << "The LCM of " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
}
