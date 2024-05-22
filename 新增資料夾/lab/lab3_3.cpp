#include <iostream>
#include <string>

using namespace std;

int main() {  
    // ----------------------
    // Please fill this blank
    
    string s;
    cin >> s;
    
    for(int i = 0; i <= s.length()-2; i++) {
        // int current = int(s[i]) - 48;
        // int next = int(s[i+1]) - 48;
        
        // cout << current;
        
        // if(current%2 == 1 && next%2 == 1) {
        //     cout << "-";
        // }
        
        // if(i == s.length()-2) {
        //     cout << next;
        // }
        
        cout << s[i];
        
        if(s[i]%2 == 1 && s[i+1]%2 == 1) {
            cout << "-";
        }
        
        if(i == s.length()-2) {
            cout << s[i+1];
        }
    }

    // ----------------------
    return 0;
}
