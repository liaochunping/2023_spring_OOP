#include <iostream>
/* add more as you need */
#include <queue>
#include <string>

using namespace std;

int gcd (int a, int b) {
  if (a == 0) return b;
  else if (b == 0) return a;
  else if (a > b) return gcd (b, a % b);
  else return gcd (a, b % a);
}

int lcm(int* a, int* b){
    int min = gcd (*a, *b);
    return *a/min * *b;
}


int main(){
    
    int n1, n2, lim;
    
    /* declare a container */
    queue<int> nums;
    
    cin >> n1 >> n2 >> lim;
    
    /* search for common multiple and insert smallest value into container first */
    int min = lcm(&n1, &n2);

    //cout << "min: " << min << endl;

    int n = lim / min;

    //cout << "n: " << n<< endl;

    for(int i = 1; i <= n; i++) {
        nums.push(min * i);
    }
    
    /* display and remove the currently lowest value in container */
    while(!nums.empty()) {
        cout << nums.front() << ", elements in container: " << n << endl;
        n--;
        nums.pop();
    }
    
    
    return 0;
}
