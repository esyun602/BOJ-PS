#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(tc-->0){
        int dp[10][1<<10] = {};
        memset(dp, -1, sizeof(dp));
        int count[1<<10] = {};
        int n,m;
        cin>>n>>m;
        vector<string> board(n);
        for(int i=0;i<n;i++){
            cin>>board[i];
        }

        bool checkStudent[1<<10][10] = {};
        bool ableComb[1<<10] = {};
        for(int i=0;i<1<<10;i++){
            bool right = false;
            ableComb[i] = true;
            for(int j=0;j<m;j++){
                if(i&1<<j){
                    count[i]++;
                    checkStudent[i][j] = true;
                    if(right){
                        ableComb[i]= false;
                    }
                    else{
                        right = true;
                    }
                }
                else{
                    right = false;
                }
            }
        }

        for(int i=0;i<1<<m;i++){
            if(!ableComb[i]){
                continue;
            }
            bool complete = true;
            for(int j=0;j<m;j++){
                if(checkStudent[i][j] && board[0][j] == 'x'){
                    complete = false;
                    break;
                }
            }
            if(complete)    dp[0][i] = count[i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<1<<m;j++){
                if(!ableComb[j]){
                    continue;
                }
                bool complete = true;
                for(int k=0;k<m;k++){
                    if(checkStudent[j][k] && board[i][k] == 'x'){
                        complete = false;
                        break;
                    }
                }
                if(complete){
                    for(int l=0;l<1<<m;l++){
                        if(dp[i-1][l] != -1 && ableComb[j|l]){
                            dp[i][j] = max(dp[i][j], dp[i-1][l] + count[j]);
                        }
                    }
                }
            }
        }
        int maxi = -1;
        for(int i=0;i<1<<m;i++){
            maxi = max(maxi, dp[n-1][i]);
        }
        cout<<maxi<<'\n';
    }
}