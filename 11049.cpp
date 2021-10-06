#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[501][501];
int main(){
    int n;
    int ret=0;
    cin>>n;
    vector<pii> v(n);
    for(int i=0;i<n;i++){
        int r,c;
        cin>>r>>c;
        v[i] = {r,c};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            dp[j][i] = 0x7fffffff;
        }
    }
    for(int i=0;i<n;i++){
        for(int k=i-1;k>=0;k--){
            for(int j=k;j<i;j++){
                dp[k][i] = min(dp[k][i], dp[k][j]+dp[j+1][i] + v[k].first*v[j].second*v[i].second);
            }
        }
        
    }
    cout<<dp[0][n-1];
}