#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

   
    int total_weight = 0;
    int total_torque = 0;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        total_weight += weight;
        total_torque += weight * i;
    }

    int pivot = total_torque / total_weight;
    if (total_torque%total_weight==0){
        cout << pivot + 1 << endl; 
    }
    else{
        cout << -1 << endl; 
    }
    return 0;
}