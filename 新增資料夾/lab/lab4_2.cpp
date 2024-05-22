#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double average(std::vector<int>& vec){
    // Please fill this blank
    
    double sum = 0;
    for(int i = 0; i < vec.size(); i++) {
        sum += vec[i];
    }
    
    return sum / vec.size();
}

double standardDev(std::vector<int>& vec){
    // Please fill this blank
    
    double ave = average(vec);
    
    double sum = 0;
    for(int i = 0; i < vec.size(); i++) {
        sum += pow(vec[i] - ave, 2);
    }
    
    return pow(sum / vec.size(), 0.5);
}