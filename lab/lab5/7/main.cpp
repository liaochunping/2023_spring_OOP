#include <bits/stdc++.h>
using namespace std;
int main(){   
    list<int> list;
    int m ,n ;
    cout << "Where to reverse the list? from m to n "<<endl;
    cin >> m>>n;
    cout << "Input your list, end  with 'q' "<<endl;
    int a;
    while(cin>>a){ 
       list.push_back(a);
    }
    reverse(next(list.begin(), m-1), next(list.begin(), n));
    cout << "After reverse "<<endl;
    for (const auto &element : list){
        cout << element << ' ';
    }
    return 0;
}