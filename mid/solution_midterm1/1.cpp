#include <iostream>
#include <vector>

using namespace std;

/* you cannot change function return type */
void fillVector(vector<unsigned long int>& vec, int le) {
    
    int totalLen = 0;
    for(int i = 1; i <= le; i++)
        totalLen += i;
    
    vec.push_back(0);
    vec.push_back(1);
    
    for(int i = 2; i < totalLen; i++) {
        vec.push_back(vec[i-1] * i);
    }
}

void printTriangle(vector<unsigned long int>& vec, int le) {
    
    if(le == 0) {
        cout << "No pyramid!";
        return;
    }
    
    for(int layer = 0; layer < le; layer++) {
        
        int startFrom = 0;
        for(int l = 0; l <= layer; l++) {
            startFrom += l;
        }
        
        for(int i = 0; i < layer+1; i++) {
            cout << vec[i+startFrom] << " ";
        }
        
        cout << endl;
    }
}

int main(){
    int le;
    cout << "Number of levels: ";
    cin >> le;
  
    if(le <= 0) cout << "No pyramid!" << endl;
    else {
        vector<unsigned long int> c;
        fillVector(c, le);
        
        printTriangle(c, le);
    }
    
    return 0;
}
