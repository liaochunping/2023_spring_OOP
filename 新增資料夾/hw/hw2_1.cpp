#include <iostream>
#include <vector>

using namespace std;

int main() {
  std::vector<int> vec = getvector();

  // ----------------------
  // Please fill this blank

	for(int i = 0; i < vec.size(); i++) {
        for(int j = i+1; j < vec.size(); j++) {
            if(vec[i] > vec[j]) {
                int temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
  
  // ----------------------

  return 0;
}
