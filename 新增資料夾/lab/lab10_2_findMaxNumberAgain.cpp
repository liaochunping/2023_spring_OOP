#include <iostream>

using namespace std;

// Implement findmax() here
template<typename T>
T findmax(T arr[], int size) {
    T max = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int main() {
    int intArr[5] = {10, 20, 50, 40, 3};
    float floatArr[5] = {1.11, 2.3, 3.14, 10.2, 4.44};
    
    cout << "Int results: " << findmax<int>(intArr, 5) << endl;
    cout << "Float results: " << findmax<float>(floatArr, 5) << endl;
    
    return 0;
}