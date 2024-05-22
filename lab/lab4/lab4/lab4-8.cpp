#include <iostream>
using namespace std;

// Fibo
int fibo(int n) {
	if (n <= 1) return n;
	return fibo(n - 1) + fibo(n - 2);
}

// Returns number of ways to reach s'th stair
int countWays(int s) {
	return fibo(s + 1);
}

int main() {
	int s = 4;
	cout << "Number of ways = " << countWays(s);
	return 0;
}
