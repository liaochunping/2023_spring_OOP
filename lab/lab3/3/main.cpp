#include<iostream>
#include<vector>
using namespace std;
int main(){
    int r,c;
    cin>>r>>c;
    cout<<endl;
        vector<vector<int>>matrix(10,vector<int>(10));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>matrix[i][j];
            }
        }
        cout<<endl;
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                cout<<matrix[j][i]<<" "; 
            }
            cout<<"\n";
        }
    
    return 0;
}