#include<bits/stdc++.h>
int dp[50] = {0, 1, 1};
int dp2[50] = {1, 0, 1};
int fibonacci_one(int n){
    if(dp[n]!=-1)
    	return dp[n];
    return dp[n] = fibonacci_one(n-1)+ fibonacci_one(n-2);
}

int fibonacci_zero(int n){
	if(dp2[n]!=-1)
		return dp2[n];
	return dp2[n] = fibonacci_zero(n-1) + fibonacci_zero(n-2);
}


int main(){
	for(int i=3;i<50;i++){
		dp[i] = -1;
		dp2[i] = -1;
	}
    int t;
    int n;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%d", &n);
        printf("%d %d\n", fibonacci_zero(n), fibonacci_one(n));
    }
}
