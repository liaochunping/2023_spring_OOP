#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num = 10;
    int& refNum = num;
    int *ptrNum = &num;
    cout << refNum << endl;
    cout << *ptrNum << endl;
    cout << ptrNum << endl;
}