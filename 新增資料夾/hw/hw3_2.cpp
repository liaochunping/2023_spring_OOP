#include <iostream>
#include <vector>
using namespace std;

void reverse_the_array(vector<int>::iterator begin, vector<int>::iterator end)
{
    int length = (end-begin);
    
    int ix = 0;
    for(auto iter = begin; iter != begin+(length/2); ++iter, ++ix) {
        int temp = *iter;
        *iter = *(begin + (length-1-ix));
        *(begin + (length-1-ix)) = temp;
        
        // cout << "temp: " << temp << endl;
        // cout << "ix: " << ix << endl;
        // cout << "(length-1-ix): " << (length-1-ix) << endl;
        // cout << endl;
    }
    
    
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5};
    
    reverse_the_array(vec.begin(), vec.end());
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}
