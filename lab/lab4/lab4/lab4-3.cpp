#include <iostream>

using namespace std;

void overload() {
    std::cout << "no arg version!" << std::endl;
}

void overload(int &i) {
    i++;
    cout << "overload: i++ = " << i << endl;
}

void overload(string s) {
    cout << "overload(s): " << s << endl;
}

int main() {
    overload();
    int i = 2;
    overload(i);
    string s = "abcde";
    overload(s);
    overload("fghij");
}