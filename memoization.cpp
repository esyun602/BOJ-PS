#include<stdio.h>

long long dp[200000] = {1, 0, 1, 1, 2};

long long division(int num)
{
	if(num<0)
		return 0;	
	if(dp[num]!=0){
		return dp[num];
	}
	int ret=0;
	ret += division(num-4) + division(num-2) + division(num-3);
	while(ret>1000000007){
		ret-=1000000007;
	}
	return dp[num] = ret;
}

int main()
{
	int Q;
	int N;
	long long num;
	scanf("%d", &Q);
	for(int i=0;i<Q;i++)
	{
		scanf("%d", &N);
		num = division(N);
		printf("%lld\n", num);
	}
}
