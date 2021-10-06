#include<bits/stdc++.h>
using namespace std;

string combination[101][101];

string stringAdd(string a, string b){
    string ret = "";
    if(a.length() > b.length()){
        while(b.length()!=a.length()){
        	
            b = '0'+b;
        }
    }
    else{
        while(b.length()!=a.length()){
            a = '0'+a;
        }
    }
    int tmp = 0;
    for(int i=a.length()-1;i>=0;i--){
        int data = (a[i]-'0') + (b[i]-'0') + tmp;
        ret = to_string(data%10) + ret;
        tmp = data/10;
    }
    if(tmp!=0){
        ret  = to_string(tmp) + ret;
    }
    return ret;
}

string findComb(int n, int m){
    if(combination[n][m]!="0"){
        return combination[n][m];
    }
    return combination[n][m] = stringAdd(findComb(n-1,m-1), findComb(n-1,m));
}

int main(){
    for(int i=0;i<101;i++){
        for(int j=0;j<101;j++){
            combination[i][j] = "0";
        }
    }
    for(int i=1;i<101;i++){
        combination[i][i] = combination[i][0] = "1";
    }
    int n,m;
    cin>>n>>m;
    findComb(n,m);
    cout<<findComb(n,m);
}
