#include <iostream>
using namespace std;

int main () {
  int ia[] = {0,1,2,3,4,5,6,7,8,9};
  int *p = ia;
  
  // while should not be modified.
  while(p != end(ia)) {
      cout << *p << " ";
      p++;
  }
  
  return 0;
}

