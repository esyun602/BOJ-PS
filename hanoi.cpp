#include<stdio.h>
int count;
int countHanoi(int num)
{
	int ret=0;
	if(num == 1)
	{
		return 1;
	}
	ret += countHanoi(num-1);
	ret += countHanoi(1);
	ret += countHanoi(num-1);
	return ret;
}
void hanoi(int now, int target, int num)
{
    if(num == 1)
    {
    	printf("%d %d\n", now, target);
		return;
	}
    int rest = now+target == 4 ? 2 : (now+target)%4;
    hanoi(now, rest, num-1);
    hanoi(now, target, 1);
    hanoi(rest, target, num-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", countHanoi(n));
    hanoi(1, 3, n);
}
