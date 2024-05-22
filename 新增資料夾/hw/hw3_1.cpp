#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ----------------------
    // Please fill this blank
    
    int num;
    vector<int> vec;
    
    while(cin >> num) {
        vec.push_back(num);
    }

    int count = 0;
    for(int i = 0; i < vec.size(); i++) {
        for(int j = i+1; j < vec.size(); j++) {
            if(vec[i] == vec[j]) {
                count++;
            }
        }
    }
    
    cout << count;

    // ----------------------
    return 0;
}
