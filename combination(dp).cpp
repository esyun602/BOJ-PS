#include<bits/stdc++.h>
using namespace std;
int dp[4000000][2];

int combination(int n, int k){
    if(k==1|| n-1==k)
        return n;
    if(dp[n-1][0]==0)
        dp[n-1][0] = combination(n-1, k-1)%1000000007;
    if(dp[n-1][1]==0)
        dp[n-1][1] = combination(n-1, k)%1000000007;
    int ret = (dp[n-1][0]+dp[n-1][1])%1000000007;
    swap(dp[n-1][0], dp[n-1][1]);
    dp[n-1][1] = 0;
    return ret;
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", combination(n, k));
}
