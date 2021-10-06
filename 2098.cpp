#include<bits/stdc++.h>
using namespace std;
int n;
int dp[16][1<<16];
int dfs(vector<vector<int> > &w,int cur, int vis){
    vis |= 1<<cur;
    if(vis == (1<<n)-1){
        if(w[cur][0]==0)    return 0xffffff;
        return w[cur][0];
    }

    if(dp[cur][vis]!=0){
        return dp[cur][vis];
    }
    dp[cur][vis] = 0xffffff;


    for(int i=0;i<n;i++){
        if((vis&(1<<i)) || w[cur][i]==0){
            continue;
        }
        dp[cur][vis] = min(dp[cur][vis], dfs(w,i,vis) + w[cur][i]);
    }
    return dp[cur][vis];
}

int main(){
    cin >> n;
    vector<vector<int> > w(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }
    cout<<dfs(w,0,0);
}
