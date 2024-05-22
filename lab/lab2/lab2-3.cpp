#include <iostream>
#include <vector>

using namespace std;

struct Rectangle {
    double l = 10;
    double w = 5;
};

int main() {
    Rectangle r;
    cout << "Enter the length:";
    cin >> r.l;
    cout << "Enter the width:";
    cin >> r.w;
    cout << "Area: " << r.w*r.l << endl;
    cout << "Perimeter: " << 2*(r.w+r.l) << endl;
    return 0;
}