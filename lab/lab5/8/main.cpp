#include <bits/stdc++.h>
using namespace std;
void findPrevSmaller(vector<int> arr, int n){
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty())
        {
            if (s.top() < arr[i])
            {
                cout << s.top() << ' ';
                break;
            }
            else {
                s.pop();
            }
        }
        if (s.empty()) {
            cout << -1 << ' ';
        }
        s.push(arr[i]);
    }
}
int main(){
    cout <<"Please input array, end  with 'q' "<<endl;
    int a;
    vector<int> arr;
    while(cin>>a){ 
       arr.push_back(a);
   }
    int n = arr.size();
    findPrevSmaller(arr, n);
    return 0;
}