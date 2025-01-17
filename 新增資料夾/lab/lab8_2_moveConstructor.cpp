#include <iostream>
#include <vector>

using namespace std;
 
class Move {
private:
    int* data;
 
public:
   
    Move(int d)
    {
        data = new int;
        *data = d;
        cout << "Constructor is called for "
             << d << endl;
    };
 
    Move(const Move& source)
        : Move( *source.data )
    {
        cout << "Copy Constructor is called -"
             << "Deep copy for "
             << *source.data
             << endl;
    }
    
    // Move Constructor
    Move(Move && source)
        : data(source.data) {
        
        cout << "Move Constructor for " << *source.data << endl;    
        source.data = nullptr;
    }
 
    ~Move()
    {
        if (data != nullptr)
 
            cout << "Destructor is called for "
                 << *data << endl;
        else
 
            cout << "Destructor is called"
                 << " for nullptr"
                 << endl;

        delete data;
    }
};


int main()
{
    vector<Move> vec;
    vec.reserve(2);
 
    vec.push_back(Move(10));
    vec.push_back(Move(20));
    return 0;
}

