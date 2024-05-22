#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int lastWeight(vector<int>& stones) {
    // int n = stones.size();
    // int total = 0;
    // for(int i = 0; i < n; i++){
    //     total += stones[i];
    // }
    // int req = total / 2;
    
    // // cout << "total: " << total << endl;
    // // cout << "req: " << req << endl;
    // // cout << "------------" << endl;
    
    // vector <bool> dp(req + 1, false);
    // dp[0] = true;
    // int maximum = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = stones[i]; j <= req; j++){
    //         dp[j] = dp[j] || dp[j - stones[i]];
    //         if(dp[j]) maximum = max(maximum, j);
            
    //         // cout << "[i, j]: " << i << ", " << j << endl;
    //         // for(auto x : dp){
    //         //     cout << x << " ";
    //         // }
    //         // cout << endl;
    //         // cout << "maximum: " << maximum << endl;
    //         // cout << "------------" << endl;
    //     }
    // }
    // return total - (2 * maximum);
    
    priority_queue<int> q;
    for(int i = 0; i < stones.size(); i++) {
        q.push(stones[i]);
    }
    
    while(q.size() > 1) {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        
        if(a != b) q.push(a-b);
    }
    
    if(q.empty()) return 0;
    else return q.top();
}