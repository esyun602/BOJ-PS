#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int dp[4][10001][3] = {};
        int n;
        int w;
        cin>>n>>w;
        vector<int> v(n+1);
        vector<int> v2(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        for(int j=1;j<=n;j++){
            cin>>v2[j];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<4;k++)
                    if(i==0)    
                        dp[k][i][j]=0;
                    else
                        dp[k][i][j] = 0xfffffff;
            }
        }
        dp[0][1][0] = dp[0][1][1] = 1;
        dp[0][1][2] = w>=v[1]+v2[1] ? 1 : 2;
        dp[1][1][0] = 0;
        dp[1][1][2] = 1;
        dp[2][1][1] = 0;
        dp[2][1][2] = 1;
        dp[3][1][2] = 0;


        for(int k=0;k<4;k++){
            for(int i=2;i<=n;i++){
                int j;
                j = i-1;
                if(w>=v[i-1]+v[i])
                    dp[k][i][0] = min(dp[k][i][0], dp[k][j][1]+1);
                dp[k][i][0] = min(dp[k][i][0], dp[k][j][2]+1);
                if(w>=v2[i-1]+v2[i])
                    dp[k][i][1] = min(dp[k][i][1], dp[k][j][0]+1);
                dp[k][i][1] = min(dp[k][i][1], dp[k][j][2]+1);
                if(w>=v[i]+v2[i])   
                    dp[k][i][2] = min(dp[k][i][2], dp[k][j][2]+1);
                if(w>=v[i]+v[i-1] && w>=v2[i-1]+v2[i]){
                    dp[k][i][2] = min(dp[k][i][2], dp[k][i-2][2]+2);
                }
                dp[k][i][2] = min(dp[k][i][2], dp[k][j][2]+2);
                dp[k][i][2] = min(dp[k][i][2], dp[k][i][0]+1);
                dp[k][i][2] = min(dp[k][i][2], dp[k][i][1]+1);
            }
        }
        int ret = 0xfffffff;
        ret = min(ret, dp[0][n][2]);
        if(w>=v[1]+v[n])
            ret = min(ret, dp[1][n][1]+1);
        if(w>=v2[1]+v2[n])
            ret = min(ret, dp[2][n][0]+1);
        if(w>=v2[1]+v2[n]&&w>=v[1]+v[n])
            ret = min(ret, dp[3][n-1][2]+2);
        cout<<ret<<'\n';
        
        /*
        for(int i=1;i<=n;i++){
            cout<<dp[0][i][2]<<' ';
        }*/
       // cout<<'\n'<<dp[0][n][2]<<' '<<dp[1][n][1]+1<<' '<<dp[2][n][0]+1<<' '<<dp[3][n-1][2]+2<<' ';
    }
}