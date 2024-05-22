#include <iostream>
#include <map>
#include <string>

using namespace std;

int value(char c) {
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
 
    return -1;
}

int romanToInt(string s) {
    int output = 0;
    
    int len = s.length();
    
    for(int i = 0; i < len; i++) {
        int current = value(s[i]);
        
        if(i+1 < len) {
            int next = value(s[i+1]);
            
            if(current >= next) {
                output += current;
            } else {
                output += next-current;
                i++;
            }
        } else {
            output += current;
        }
    }
    
    return output;
}

int main() {
    
    
    string s = "MCMXCIV";
    cout << romanToInt(s);
    
    return 0;
}