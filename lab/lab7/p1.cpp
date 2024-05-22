#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int* arr = new int[MAX_SIZE]; // dynamically allocate array
    int num, sum = 0, i = 0;

    while (true) {
        cin >> num;
        if (num < 0) {
            break;
        }
        arr[i] = num;
        sum += num;
        i++;
    }

    delete[] arr; // free memory allocated by new operator
    cout << sum << endl;
    return 0;
}
