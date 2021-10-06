#include<bits/stdc++.h>
using namespace std;
char str[3500][6500];

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    str[0][n] = '*';
    for(int i=0;i<n-1;i++){
        for(int j=n-i;j<=n+i;j++){
            if(str[i][j]=='*'){
                if(i%3 == 0){
                    str[i+1][j+1] = str[i+1][j-1] = '*';
                }
                else if(i%3 == 1){
                    str[i+1][j+1] = str[i+1][j] = str[i+1][j-1] = '*';
                }
                else{
                    if(str[i][j+1] != '*' && str[i][j+2] != '*'){
                        str[i+1][j+1] = '*';
                    }
                    else if(str[i][j-1]!='*' && (j-2<0 || str[i][j-2]!='*')){
                        str[i+1][j-1] = '*';
                    }
                }
                
            }
            
        }
        
        
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(str[i][j] == '*'){
                cout<<'*';
            }
            else{
                cout<<' ';
            }
        }
        cout<<'\n';
    }
}
