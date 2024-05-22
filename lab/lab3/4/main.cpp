#include<iostream>
#include<string>
using namespace std;
int main() {
    string a;
    int j = 0;
    cin>> a ;
    int length = a.length();
    for(int i=0,j=length-1; i<j; i++,j--){
        if(a[j]!=a[i]){
            cout<<"no";
            return 0;}
    
    }
   
    cout<<"yes";
    return 0;
}