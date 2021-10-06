#include<bits/stdc++.h>
//�ݺ��� ����ؼ� �Ҷ����� ��� --> �̸� �ѹ� ����ؼ� �迭�� ��ü ex) ��, ��, ... 
//���� ��ȹ�� --> �տ����� ���� x �����ſ��� �ϳ��� �ٿ��� or ū�Ÿ� ������ �������� �и� 
// 2���̻��� ���(ū����)�� ������ dp���� ������ 2���� ������.(�߰��� �� �̿�) 
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
