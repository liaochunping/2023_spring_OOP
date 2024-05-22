#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> fib(int n) {
    vector<int> nums = {0, 1};
    
    for(int i = 2; i <= n; i++) {
        nums.push_back(nums[i-2] + nums[i-1]);
    }
    
    return nums;
}

int num_ways_to_climb(int stairs) {
    
    int n = stairs + 2;
    vector<int> vec = fib(n);
    return vec[n-1];
}