#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ivec(10, 1);
    int ratio;
    cin >> ratio;
	
  	// your codes
  	
  	cout << ivec[0] << " ";
  	
  	for(auto iter = ivec.begin()+1; iter != ivec.end(); ++iter) {
        *iter = *(iter-1) * ratio;
        cout << *iter << " ";
  	}
    
    return 0;
}
