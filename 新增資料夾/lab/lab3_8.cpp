#include <iostream>
#include <vector>
using namespace std;

vector<int>::iterator find_min_element(vector<int>::iterator begin, vector<int>::iterator end) {
   
    int min = *begin;
    vector<int>::iterator minp = begin;
    for(auto iter = begin+1; iter != end; ++iter) {
        if(*iter < min) {
            min = *iter;
            minp = iter;
        }
    }
   
    return minp;
   
}
