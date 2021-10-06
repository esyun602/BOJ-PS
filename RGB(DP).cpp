#include<bits/stdc++.h>
using namespace std;
int n;
int dp[3];
int arr[3];
int main(){
    int cost[3];
    int a=1, b=2;
    int before;
    int m;
    scanf("%d", &n);
    scanf("%d %d %d", &dp[0],  &dp[1], &dp[2]);
    for(int i=1;i<n;i++){
        scanf("%d %d %d", &cost[0], &cost[1], &cost[2]);
        for(int j=0;j<3;j++){
            arr[j] = min(dp[a]+cost[j], dp[b]+cost[j]);
            ++a%=3;
            ++b%=3;
        }
        for(int k=0;k<3;k++){
        	dp[k] = arr[k];
		}
    }
    int mini = min(min(dp[0], dp[1]), dp[2]);
    printf("%d", mini);
}
