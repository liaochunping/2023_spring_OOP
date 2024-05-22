#include<bits/stdc++.h>
using namespace std;
int main(){   
    vector<int>nums,results;
    deque<int>q;
    int k,n,a;
    cin >> n;
    cin >> k;
    for(int i=0 ; i<n ; i++){
            cin>>a;
            nums.push_back(a);
    }
    for (int i=0; i<nums.size(); i++){
            while (q.size()>0 && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);

            if (q.front()<=i-k){
                q.pop_front();
            }
            if (i>=k-1){
                results.push_back(nums[q.front()]);
            }
    }
    for(auto &p : results){
        cout<<p<<" ";
    }
return 0;
}
