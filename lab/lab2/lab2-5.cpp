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
    
    for(int i = 0; i < vec.size(); i++) {
        for(int j = i+1; j < vec.size(); j++) {
            if(vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    
    cout << "Sorted vector: ";
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}