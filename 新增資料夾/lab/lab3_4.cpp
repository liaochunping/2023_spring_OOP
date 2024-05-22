#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ----------------------
    // Please fill this blank
    
    int num;
    vector<int> vec;
    vector<int> count(101, 0);
    
    while(cin >> num) {
        vec.push_back(num);
    }

    for(int i = 0; i < vec.size(); i++) {
        count[vec[i]]++;
    }
    
    for(int i = 0; i < count.size(); i++) {
        if(count[i] % 2 == 0 && count[i] > 0) {
            cout << i << " ";
        }
    }

    // ----------------------
    return 0;
}
