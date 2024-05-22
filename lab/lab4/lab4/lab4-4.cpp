#include <iostream>
#include <vector>
using namespace std;

int findLucky(vector<int>& arr) {
    const int MAX_NUM = 500; // maximum possible value in arr
    vector<int> freq(MAX_NUM + 1, 0);
    for (int num : arr) {
        freq[num]++;
    }
    int largestLucky = -1;
    for (int i = 1; i <= MAX_NUM; i++) {
        if (freq[i] == i && i > largestLucky) {
            largestLucky = i;
        }
    }
    return largestLucky;
}

int main() {
    vector<int> arr = {2, 2, 3, 4, 5, 5, 5, 5};
    int largestLucky = findLucky(arr);
    if (largestLucky == -1) {
        cout << "There is no lucky integer in the array" << endl;
    } else {
        cout << "The largest lucky integer in the array is " << largestLucky << endl;
    }
    return 0;
}
