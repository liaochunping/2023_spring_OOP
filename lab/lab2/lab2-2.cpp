#include <iostream>
#include <vector>

using namespace std;

void swap(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int num1 = 5;
    int num2 = 10;
    std::cout << "Before swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    swap(&num1, &num2);
    std::cout << "After swap: num1 = " << num1 << ", num2 = " << num2 << std::endl;
    return 0;
}
