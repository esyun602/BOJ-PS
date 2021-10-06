#include<bits/stdc++.h>
using namespace std;

int dp[1500000] = {0, 1, 1};

int main(){
    long long n;
    scanf("%lld", &n);
    int fibonacci;
    for(int i=0;i<=n%1500000;i++){
    	if(dp[i]==0)
    		dp[i] = (dp[i-1]+dp[i-2])%1000000;
	}
	printf("%d", dp[n%1500000]);
}
