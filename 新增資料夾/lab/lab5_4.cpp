#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPangram(string sentence) {
    
    vector<int> count(26, 0);
    for(int i = 0; i < sentence.length(); i++) {
        count[int(sentence[i]) - 97]++;
    }
    
    for(int i = 0; i < count.size(); i++) {
        if(count[i] == 0) return false;
    }
    
    return true;
}

int main() {
    
    string s = "leetcode";
    cout << isPangram(s);
    
    return 0;
}