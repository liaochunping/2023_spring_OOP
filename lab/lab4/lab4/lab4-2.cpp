#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void getInput(vector<int>& v, int n){
    cout << "Give vector elements: ";
    int j;
    for(int i = 0; i < n; i++){
        cin >> j; 
        v.push_back(j);
    }
}

double average(const vector<int>& v){
    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    
    return sum / v.size();
}

double standardDev(const vector<int>& v){
    double ave = average(v);
    
    double sum = 0;
    for(int i = 0; i < v.size(); i++) {
        sum += pow(v[i] - ave, 2);
    }
    
    return pow(sum / v.size(), 0.5);
}

int main() {
    cout << "Your vector length: ";
    int n;
    cin >> n;
    
    vector<int> vec;
    getInput(vec, n);
    
    cout << "mean: " << average(vec) << endl;
    cout << "Std: " << standardDev(vec);
    
    return 0;
}