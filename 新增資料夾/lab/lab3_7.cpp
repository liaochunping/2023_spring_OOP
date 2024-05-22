using namespace std;

void absolute(vector<int>::iterator begin, vector<int>::iterator end)
{
    for(auto iter = begin; iter != end; ++iter) {
        if(*iter < 0) {
            *iter *= -1;
        }
    }  
}
