#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<long long>> matrixMultiply(vector<vector<long long>> &v1, vector<vector<long long>> &v2){
    vector<vector<long long>> ret(5*n,vector<long long>(5*n,0));
    for(int i=0;i<5*n;i++){
        for(int j=0;j<5*n;j++){
            for(int k=0;k<5*n;k++){
                ret[i][j] += (v1[i][k] * v2[k][j])%1000003;
                ret[i][j] %= 1000003;
            }
        }
    }
    return ret;
}

vector<vector<long long>> matrixPower(vector<vector<long long>> &v, int t){
    if(t==1){
        return v;
    }
    vector<vector<long long>> tmp(5*n,vector<long long>(5*n,0));
    tmp = matrixPower(v,t/2);    
    tmp = matrixMultiply(tmp,tmp);
    if(t%2!=0){
        tmp = matrixMultiply(tmp,v);
    }
    return tmp;
}

int main(){
    int s,e,t;
    cin>>n>>s>>e>>t;
    s--;
    e--;
    vector<vector<long long>> adj(5*n, vector<long long>(5*n,0));
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++){
            if(s[j]-'0'==0) continue;
            for(int k=0;k<s[j]-'0'-1;k++){
                adj[5*i+k][5*i+k+1] = 1;
            }
            adj[5*i+s[j]-'0'-1][5*j] = 1;
        }
    }

    adj = matrixPower(adj, t);/*
    for(int i=0;i<5*n;i++){
        for(int j=0;j<5*n;j++){
            cout<<adj[i][j]<<' ';
            if(j%5 == 4){
                cout<<'|'<<' ';
            }
        }
        if(i%5 == 4){
            cout<<endl<<"==================";
        }
        cout<<endl;
    }*/
    cout<<adj[s*5][e*5];

}