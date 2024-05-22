#include <iostream>
#include <string>

using namespace std;

int main() {  
    // ----------------------
    // Please fill this blank
    
    string s;
    cin >> s;
    
    for(int i = s.length()-1; i >= 0; i--) {
        cout << s[i];
    }

    // ----------------------
    return 0;
}
