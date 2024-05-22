#include <iostream>
using namespace std;

struct IntArray{
    int* ia;
    int n;
};

IntArray creatIntArray() {
    IntArray* output = new IntArray();
    cin >> output->n;
    output->ia = new int[output->n];
    
    for(int i = 0; i < output->n; i++) {
        cin >> output->ia[i];
    }
    
    return *output;
};

int findMax(const IntArray& a) {
    int max = 0;
    int maxIndex = 0;
    for(int i = 0; i < a.n; i++) {
        if(a.ia[i] > max) {
            max = a.ia[i];
            maxIndex = i;
        }
    }
    return maxIndex;
};

void printIntArray(const IntArray& a) {
    for(int i = 0; i < a.n; i++) {
        cout << a.ia[i] << " ";
    }
};

void deleteIntArray(IntArray& a) {
    delete a.ia;
};

int main(){
    IntArray intArray = creatIntArray();
    int i = findMax(intArray);
    cout << "Max value in integer array is: " << intArray.ia[i] << endl;
    printIntArray(intArray);
    deleteIntArray(intArray);
    
    return 0;
}
