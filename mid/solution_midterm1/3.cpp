#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Person{
string name;
int age;
};

int main(){
    string s;
    int age;

    list<Person> li;
    auto it = li.begin();
    int count = 0;
    while(1){
        cin >> s;
        if(s == "exit!") break; 
        // auto it = li.begin();
        // advance(it,(li.size()/2));
        cin >> age;
        Person st;
        st.name = s;
        st.age = age;
        li.insert(it, st);
        if(count % 2 == 0)
            it--;
        count++;
    }
    for(auto i : li)
        cout << i.name << ", " << i.age << endl;
    
    return 0;
}


