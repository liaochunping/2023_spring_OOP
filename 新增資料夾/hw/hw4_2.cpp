#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

string reverse(string s) {
    int len = s.length();
    int n = len-1;
    for(int i = 0; i < len/2; i++) {
        swap(s[i], s[n]);
        n--;
    }
    return s;
}

int palindromic(string& s) {
    int sum = 0;
    int len = s.length();
    for(int sublen = 1; sublen <= len; sublen++) {
        for(int i = 0; i <= len-sublen; i++) {
            string substring = s.substr(i, sublen);
            // cout << i << " " << i+sublen << " " << substring << " " << endl;
            if(substring.compare(reverse(substring)) == 0) {
                sum++;
            }
        }
    }
    
    return sum;
}

int main() {
    
    string s = "aaa";
    // cout << s.substr(1, 1);
    cout << palindromic(s);
    
    return 0;
}