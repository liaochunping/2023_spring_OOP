#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGE(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int> output;
    
    for(int i = 0; i < nums1.size(); i++) {
        for(int j = 0; j < nums2.size(); j++) {
            if(nums2[j] == nums1[i]) {
                int next = -1;
                for(int k = j+1; k < nums2.size(); k++) {
                    if(nums2[j] < nums2[k]) {
                        next = nums2[k];
                        break;
                    }
                }
                output.push_back(next);
            }
        }
    }
    
    return output;
}

int main() {
    vector<int> a = {4, 1, 2};
    vector<int> b = {1, 3, 4, 2};
    vector<int> c = nextGE(a, b);
    
    for(int i = 0; i < c.size(); i++) {
        cout << c[i] << ", ";
    }
    return 0;
}