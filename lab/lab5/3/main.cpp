#include<bits/stdc++.h>
using namespace std;
int main(){   
    map<string ,size_t> word_count;
    string word;
    int n;
    cout<< "How many names? "<<endl;
    cin>>n;
    for(int i = 0 ; i<n ; i++){
        cin>>word;
        ++word_count[word];
    }
    for(const auto &w:word_count){
        cout<<"Name: "<<w.first<< ", Value:  "<<w.second<<endl;
    }
    
    
return 0;
}
