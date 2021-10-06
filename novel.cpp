#include<bits/stdc++.h>
//반복문 사용해서 할때마다 계산 --> 미리 한번 계산해서 배열로 대체 ex) 합, 곱, ... 
//동적 계획법 --> 앞에서만 생각 x 작은거에서 하나씩 붙여감 or 큰거를 작은거 여러개로 분리 
// 2개이상의 덩어리(큰문제)로 나뉠때 dp에서 문제를 2개로 나눈다.(중간값 등 이용) 
using namespace std;
int dp[500][500];
int cost[500];
int costsum[501];
int costinv;
int t, k;
int solve(int i, int j){
	if(dp[i][j]!=-1)
		return dp[i][j];
	int mini = ~(1<<31);
	for(int l=i;l<j;l++){
		mini = min(mini, solve(i, l)+solve(l+1, j)+costsum[j]- (i==0 ? 0 : costsum[i-1]));
	}
	dp[i][j] = mini;
	return dp[i][j];
}


int main(){

    
    scanf("%d", &t);
    while(t--){
		memset(dp, -1, sizeof(dp));
        scanf("%d", &k);
        for(int i=0;i<k;i++){
        	dp[i][i] = 0;
            scanf("%d", &cost[i]);
        }
        costsum[0] = cost[0];
        for(int i=1;i<k;i++){
        	costsum[i] = costsum[i-1]+cost[i];
        	dp[i-1][i] = cost[i-1]+cost[i];
		}
		solve(0, k-1);
        printf("%d\n", dp[0][k-1]);
    }

}
