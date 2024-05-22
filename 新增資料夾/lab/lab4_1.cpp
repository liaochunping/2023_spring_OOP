#include <iostream>
#include <math.h>

using namespace std;

double average(int arr[], size_t& n){
    // Please fill this blank
  
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    return sum / n;
}

double standardDev(int arr[], size_t& n){
    // Please fill this blank
    
    double ave = average(arr, n);
    
    double sum = 0;
    for(int i = 0; i < n; i++) {
        sum += pow(arr[i] - ave, 2);
    }
    
    return pow(sum / n, 0.5);
}
