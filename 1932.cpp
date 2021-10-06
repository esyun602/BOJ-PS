#include<bits/stdc++.h>
using namespace std;
int n;
int dp[500][500];
int dfs(vector<vector<int>> &v, int i, int j){
    if(i==n){
        return 0;
    }
    if(dp[i][j] != -1)    return dp[i][j];
    int left = dfs(v, i+1, j) + v[i][j];
    int right = dfs(v, i+1, j+1) + v[i][j];
    return dp[i][j] = max(left, right);
}


int main(){
    cin>>n;
    memset(dp, -1, sizeof(dp));
    vector<vector<int> > v(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            int a;
            cin>>a;
            v[i].push_back(a);
        }
    }
    cout<<dfs(v,0,0);
}