#include <iostream>
#include <ctime>

class RandomArray{
    int n;
    int* ir;
    size_t static seed_time;

    public:
    RandomArray(): n(5){ }
    RandomArray(int num): n(num){ }
    
    static void setSeed(){ srand(seed_time);}
    void setSeed(size_t time);
    void loadArray(){
        ir = new int[n];
        for(int i = 0; i < n; i++) ir[i] = rand()%1000;
    }
    void printArray(){ for(int i = 0; i < n; i++) std::cout << ir[i] << "\t"; std::cout << std::endl; }
    void freeArray(){ delete[] ir;}
};

size_t RandomArray::seed_time = time(0);

void RandomArray::setSeed(size_t time){
    srand(time);
}

int main(){
    RandomArray ra(3);
    RandomArray::setSeed();

    std::cout << "Using array 1: \n";
    for(int i = 0; i < 5; i++){
        ra.loadArray();
        ra.printArray();
        ra.freeArray();
    }

    RandomArray ra2;
    ra2.loadArray();
    std::cout << "Array 2: \n";
    ra2.printArray();
    ra2.freeArray();
}
