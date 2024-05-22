#include <bits/stdc++.h>
using namespace std;
int findMinCost(vector<int> const &prices)
{
    priority_queue<int, vector<int>, greater<int>> pq(prices.begin(), prices.end());
    int cost = 0;
    while (pq.size() > 1)
    {
        int x = pq.top();
        pq.pop();
 
        int y = pq.top();
        pq.pop();
 
        int sum = x + y;
 
        pq.push(sum);
 
        cost += sum;
    }
 
    return cost;
}
 
int main()
{   
    cout << "Input your length of every ropes, end  with 'q' "<<endl;
    int a;
    vector<int> prices ;
    while(cin>>a){ 
       prices.push_back(a);
   }
    
    
    cout << "The minimum cost is " << findMinCost(prices);
 
    return 0;
}