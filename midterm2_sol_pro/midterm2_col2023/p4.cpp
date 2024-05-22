#include <iostream>

using namespace std;

template <class T>
class OOPStack{
public:
   OOPStack(int = 2);
   ~OOPStack(){ delete [] vecPtr; } // this is important!!!
   void place(const T&);
   T pop(); 
   int getSize(){ return size;  }

private:
   int size; // Number of T objects stored in Stack
   int capacity; // Number of T elements allocated
   T* vecPtr;
};

//constructor with the default size 2
template <class T>
OOPStack<T>::OOPStack(int s){
   size = 0; 
   capacity = s; 
   vecPtr = new T[capacity] ;
}

// push an element onto the vector
template <class T>
void OOPStack<T>::place(const T& item){
   if (size < capacity){
      vecPtr[++size-1] = item ;
   }
   else if(size == capacity){
      T* newVec = new T[2*capacity];
      for(int i = 0; i < capacity; i++)
         newVec[i] = vecPtr[i];
      delete[] vecPtr;
      vecPtr = newVec;
      capacity *= 2;
      vecPtr[++size-1] = item ;
      cout << "OOPStack capacity doubled to " << capacity << endl;
   }
}

// pop an element off the vector
template <class T>
T OOPStack<T>::pop() {
   if (size > 0){
      return vecPtr[--size] ;   
   }
   return 0 ; // pop unsuccessful 
}

int main(){
   cout << "int case:" << endl;
   OOPStack<int> a;
   for(int i = 0; i < 10; i++){
      a.place(i*i);
   }
   cout << a.pop() << endl;
   cout << a.getSize() << endl;
   
   cout << "bool case:" << endl;
   OOPStack<bool> b(10); // constructor for capacity of 10
   for(int i = 0; i < 30; i++){
      b.place(i%3==0);
   }
   cout << b.pop() << endl;
   cout << b.pop() << endl;
   cout << b.pop() << endl;
}






