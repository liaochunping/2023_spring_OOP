#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int** A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int** B = new int*[m];
    for (int i = 0; i < m; i++) {
        B[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }

    int** C = new int*[n];
    for (int i = 0; i < n; i++) {
        C[i] = new int[n];
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < m; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] A[i];
        delete[] C[i];
    }
    for (int i = 0; i < m; i++) {
        delete[] B[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
