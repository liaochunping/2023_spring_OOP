#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// vector<int> plusOne(vector<int> &digits) {
    
//     // get actual number
//     int actualNum = 0;
//     int len = digits.size();
//     for(int i = 0; i < len; i++) {
//         actualNum += digits[i] * pow(10, len-1-i);
//     }
    
//     // plus one
//     actualNum += 1;
    
//     // convert to vector (in reverse order)
//     vector<int> output;
//     while(actualNum != 0) {
//         output.push_back(actualNum%10);
//         actualNum /= 10;
//     }
    
//     // reverse the vector
//     int j = output.size() - 1;
//     for(int i = 0; i < output.size()/2; i++) {
//         swap(output[i], output[j]);
//         j--;
//     }
    
//     return output;
// }

vector<int> plusOne(vector<int> &digits) {
    int len = digits.size();
    for(int i = len-1; i >= 0; i--) {
        if(digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] += 1;
            return digits;
        }
    }
    
    if(digits[0] == 0) {
        digits.insert(digits.begin(), 1);
    }
    return digits;
}

int main() {
    vector<int> a(100, 9);
    vector<int> b = plusOne(a);
    
    for(int i = 0 ; i < b.size(); i++) {
        cout << b[i] << ", ";
    }
    
    return 0;
}