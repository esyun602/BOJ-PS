#include<bits/stdc++.h>
using namespace std;
int dp[1000000][2] = {};
int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][0]+1;
        dp[i][1] = i-1;
        if(i%2==0 && dp[i][0] > dp[i/2][0]+1){
            dp[i][0] = dp[i/2][0]+1;
            dp[i][1] = i/2;
        }
        if(i%3 == 0 && dp[i/3][0]+1 < dp[i][0] ){
            dp[i][0] = dp[i/3][0]+1;
            dp[i][1] = i/3;
        }

    }
    cout<<dp[n][0]<<'\n';
    int k = n;
    while(k>0){
        cout<<k<<' ';
        k = dp[k][1];
    }
}