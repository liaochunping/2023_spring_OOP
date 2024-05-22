#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> result(2 * n);
    for (int i = 0, j = n, k = 0; i < n; i++, j++, k += 2) {
        result[k] = nums[i];
        result[k + 1] = nums[j];
    }
    return result;
}

int main() {
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int n = 3;
    vector<int> shuffled = shuffle(nums, n);
    for (int num : shuffled) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
