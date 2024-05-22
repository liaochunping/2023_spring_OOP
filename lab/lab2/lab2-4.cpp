#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<int> vec;
    
    cout << "Enter the elements: ";
    int input;
    while(cin >> input) {
        vec.push_back(input);
    }
    
    int max = vec[0];
    int min = vec[0];
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] > max)
            max = vec[i];
        if(vec[i] < min)
            min = vec[i];
    }
    
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
}