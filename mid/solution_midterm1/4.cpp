#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> city(n + 2, vector<int>(n + 2, 0));  // 二維 vector，大小為 (n+2)*(n+2)，初始值為 0
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> city[i][j];
        }
    }
    
    int intersections = 0, tJunctions = 0, turns = 0, deadEnds = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (city[i][j] == 1) {
                int count = 0;
                count += (city[i-1][j] == 1) + (city[i+1][j] == 1) + (city[i][j-1] == 1) + (city[i][j+1] == 1);  // 計算周圍有幾個 1
                if (count == 4) {
                    intersections++;
                } else if (count == 3) {
                    tJunctions++;
                } else if (count == 2) {
                    if ((city[i-1][j] == 1 && city[i+1][j] == 1) || (city[i][j-1] == 1 && city[i][j+1] == 1)) {
                        // 兩個相鄰的 1 在同一條直線上，不是 turn
                    } else {
                        turns++;
                    }
                } else if (count == 1) {
                    deadEnds++;
                }
            }
        }
    }
    
    cout << intersections << endl << tJunctions << endl << turns << endl << deadEnds << endl;
    
    return 0;
}