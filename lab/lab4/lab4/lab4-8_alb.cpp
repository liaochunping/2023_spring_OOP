#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// recursion without memoization: inefficient
int steps(int n){
    if(n == 1) return 1;
    else if(n == 2) return 2;
    else return steps(n-1) + steps(n-2);
}

int steps(int n, vector<int>& v){
    if(v[n-1] == 0)
        v[n-1] = steps(n-1, v) + steps(n-2, v);
    return v[n-1];
}

int main()
{
    
    int n, ans;
    cout << "Input: ";
    cin >> n;
    
    auto start_time = chrono::high_resolution_clock::now();
    
    vector<int> v(n,0);
    v[0] = 1;
    v[1] = 2;
    
    //ans = steps(n, v);
    ans = steps(n);
    
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    
    cout << "Running time: " << duration << " microseconds" << endl;
    
    cout << "Output: " << ans;

    return 0;
}