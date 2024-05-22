#include <iostream>
using namespace std;

int main() {
    int a1; 
    cout<< "please input a number"<<endl;
    cin >> a1;

    int a2 = a1; 

    for (int b = 2; a2 > 1; b++) { 
        int iter = 0; 

        while (a2 % b == 0) { 
            iter++; 
            a2 /= b; 
        }

        if (iter > 0) {
            cout << b << "^" << iter; 
            if (a2 > 1) { 
                cout << " * "; 
            }
        }
    }

    return 0;
}