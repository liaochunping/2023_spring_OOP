#include <iostream>

using namespace std;

struct IntArray{
    int* ia;
    int n;
};

IntArray creatIntArray();
int findMax(const IntArray&);
void printIntArray(const IntArray&);
void deleteIntArray(IntArray&);

int main(){
    IntArray intArray = creatIntArray();
    int i = findMax(intArray);
    cout << "Max value in integer array is: " << intArray.ia[i] << endl;
    printIntArray(intArray);
    deleteIntArray(intArray);
    
    return 0;
}

IntArray creatIntArray(){
    IntArray inta;
    cout << "How many integers do you want to input: ";
    cin >> inta.n;
    
    cout << "Please input the integers: ";
    
    inta.ia = new int[inta.n];
    
    for(int i = 0; i < inta.n; ++i) cin >> inta.ia[i];
    
    return inta;
}
int findMax(const IntArray& iArray){
    int val = -9999999999999;
    int pos = -1;
    for(int i = 0; i < iArray.n; ++i){
        if(val < iArray.ia[i]){
            val = iArray.ia[i];
            pos = i;
        }
    }
    return pos;
}
void printIntArray(const IntArray& iArray){
    cout << "Integer Array: ";
    for(int i = 0; i < iArray.n; ++i)
        cout << iArray.ia[i] << " ";
    cout << endl;
}

void deleteIntArray(IntArray& iArray){
    delete[] iArray.ia;
}