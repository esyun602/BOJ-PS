#include<bits/stdc++.h>
using namespace std;
bool isPalindrom[2001][2001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        if(v[i] == v[i+1]){
            isPalindrom[i][i+1] = true;
        }
        isPalindrom[i][i] = true;
    }
    isPalindrom[n][n] = true;
    for(int i=2;i<n;i++){
        int j=1;
        while(i-j>=1 && i+j<=n && isPalindrom[i-j+1][i+j-1]){
            if(v[i-j] == v[i+j]){
                isPalindrom[i-j][i+j] = true;
            }
            j++;
        }
        j=1;
        while(i-j>=1 && i+j+1<=n && isPalindrom[i-j+1][i+j]){
            if(v[i-j] == v[i+j+1]){
                isPalindrom[i-j][i+j+1] = true;
            }
            j++;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int s,e;
        cin>>s>>e;
        if(isPalindrom[s][e])   cout<<1<<'\n';
        else    cout<<0<<'\n';
    }
}