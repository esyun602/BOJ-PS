#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int house[1000][3];
    for(int i=0;i<n;i++){
        cin>>house[i][0]>>house[i][1]>>house[i][2];
    }
    int dp[3][3];
    for(int i=0;i<9;i++){
        dp[i/3][i%3] = 0xfffffff;
    }
    dp[0][0] = house[0][0];
    dp[1][1] = house[0][1];
    dp[2][2] = house[0][2];
    for(int i=1;i<n;i++){
        for(int j=0;j<3;j++){
            int a = min(dp[j][1], dp[j][2]) + house[i][0];
            int b = min(dp[j][0], dp[j][2]) + house[i][1];
            int c = min(dp[j][0], dp[j][1]) + house[i][2];
            dp[j][0] = a;
            dp[j][1] = b;
            dp[j][2] = c;
        }
    }
    cout<<min(min(min(dp[0][1],dp[0][2]), min(dp[1][0], dp[1][2])), min(dp[2][0], dp[2][1]));
}