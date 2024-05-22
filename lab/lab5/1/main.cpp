#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    int input;
    int iter;
    stack<int> s;
    cout << "How many people ?" <<endl;
    cin >> n;
    iter = n;
    cout << "Please input all the number !" <<endl;
    while(iter>0){
        cin>> input;
        if(s.empty()==false){
            if(input == s.top()){
                s.pop();
            }
        }
        else{
                s.push(input);
        }
        iter--;
    }
    if(s.empty()==true){
        cout << "excellent!!";
    }
    else{
        cout << "Oh no!!";
    }
    
return 0;
}
