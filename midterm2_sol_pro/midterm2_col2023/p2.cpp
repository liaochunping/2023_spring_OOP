#include <iostream>
#include <vector>
#include <string>

class Vec{
  int* v;
  int n;
public:
  Vec();
  int findMin(int start);
  void swapPos(int pos1, int pos2);
  void selectionSort();
  void printOut() const;
  
  // important!!!!!!
  ~Vec(){ delete[] v; }
};

std::ostream& operator << (std::ostream& out, const Vec& v)
{
    v.printOut();
	return out;
}

Vec::Vec(){
  std::cout << "Please input how many numbers you wish to sort: ";
  std::cin >> n;

  v = new int[n];

  std::cout << "Please input the numbers: ";
  for(int i = 0; i < n; ++i) std::cin >> v[i];
}

int Vec::findMin(int start){
    if(start >= n) return -1;

    int temp = 100;
    int pos = -1;

    for(int i = start; i < n; ++i){
        if(v[i] < temp){
            temp = v[i];
            pos = i;
        }
    }
    return pos;
}

void Vec::swapPos(int pos1, int pos2){
    std::cout << "Swaping values: (" << v[pos1] << ", " << v[pos2] << "): " ; 
    int temp = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = temp;
}

void Vec::selectionSort(){
    for(int i = 0; i < n - 1; ++i){
        int idx = findMin(i);
        swapPos(i, idx);
        std::cout << *this;
    }
}

void Vec::printOut() const {
    for(int i = 0; i < n; ++i){
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

using namespace std;

int main(){
    Vec v;
    cout << "Original input: " << v;
    v.selectionSort();
    cout << "Final result: " << v;
}
