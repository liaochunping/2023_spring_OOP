#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool validateStack(vector<int>& pushed, vector<int>& popped) {
    
    int len = pushed.size();
    
    stack<int> s;
    s.push(pushed[0]);
    
    int i = 1;
    int j = 0;
    while(j < len) {
        if(s.top() == popped[j]) {
            s.pop();
            j++;
        }
        else {
            s.push(pushed[i]);
            i++;
        }
    }
    
    return s.empty();
}

int main() {
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped = {4, 3, 5, 2, 1};
    
    cout << validateStack(pushed, popped);
    return 0;
}