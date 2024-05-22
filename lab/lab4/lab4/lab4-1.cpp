#include <iostream>
#include <math.h>

using namespace std;

void getInput(int* ar, int n){
    cout << "Give array elements: ";
    for(int i = 0; i < n; i++)
        cin >> ar[i]; 
}

double average(int arr[], int n){
    // Please fill this blank
  
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    return sum / n;
}

double standardDev(int arr[], int n){
    // Please fill this blank
    
    double ave = average(arr, n);
    
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += pow(arr[i] - ave, 2);
    }
    
    return pow(sum / n, 0.5);
}

int main() {
    cout << "Your array length: ";
    int n;
    cin >> n;
    
    int ar[n];
    getInput(ar, n);
    
    cout << "mean: " << average(ar, n) << endl;
    cout << "Std: " << standardDev(ar, n);
    
    return 0;
}