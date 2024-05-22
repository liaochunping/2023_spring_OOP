#include<bits/stdc++.h>
using namespace std;
int main(){
string a;
while(getline(cin,a)){
    for(int i=0;i<a.size();i++){
        a[i]=a[i]+7;
        cout<<a[i];
    }
    cout<<endl;
    
}
return 0 ;
}