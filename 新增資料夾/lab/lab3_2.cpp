#include <iostream>
#include <string>

using namespace std;

int main() {  
    // ----------------------
    // Please fill this blank
    
    string s;
    
    while(cin >> s) {
        if(s.begin() != s.end()) {
            auto it = s.begin();
            *it = toupper(*it);
            cout << s << " ";
        }
    }

    // ----------------------
    return 0;
}
