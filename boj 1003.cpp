#include<bits/stdc++.h>
int dp[50];

int f(int n){
    if(dp[n]!=-1)
        return dp[n];
    return dp[n] = f(n-1) + f(n-2);
}

void run(){
    int n;
    scanf("%d", &n);
    if(n==0)
        printf("1 0");
    else printf("%d %d", f(n-1), f(n));
}


int main(){
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    dp[1] = 1;
    int t;
    scanf("%d", &t);
    while(t--) run();
}