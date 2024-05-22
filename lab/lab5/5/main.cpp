#include <bits/stdc++.h>
using namespace std;
 
bool subArrayExists(int arr[], int N){
    unordered_set<int> sumSet;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (sum == 0 || sumSet.find(sum) != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}
int main()
{
    
    int N ;
    cout<<"How many number in the array?"<<endl;
    cin>>N;
    cout<<"Input the array"<<endl;
    int arr[N];
    for(int i =0 ; i<N ;i++){
        cin>>arr[i];
    }
    if (subArrayExists(arr, N))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}