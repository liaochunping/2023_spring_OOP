#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    queue<int> q ;
    cout <<"How many card?"<<endl;
    cin >> n;
    for(int i=1;i<=n;i++){
    q.push(i);
    }
    cout <<"Discarded cards: " ;
    while(q.front()!=q.back()){
    cout<<q.front()<<" ";
    q.pop();
        if(!q.empty()){
            int last=q.front();
            q.pop();
            q.push(last);
        }
    }
    cout<<endl;
    cout <<"Remaining card: " << q.front() ;
return 0;
}
