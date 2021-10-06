#include<stdio.h>
#include<math.h>
int main()
{
    int N, M, a, min = !(1<<31);
    scanf("%d %d", &N, &M);
    int card[100]={};
    for(int i=0;i<N;i++)
        scanf("%d", card+i);
    for(int i=0;i<N-2;i++)
        for(int j=i+1;j<N-1;j++)
            for(int k=j+1;k<N;k++)
            {
            	printf("%d, %d, %d\n", i, j, k);
                a = card[i]+card[j]+card[k];
                if(M<a) continue;
                min = M-min>M-a ? a : min;
            }
    printf("%d", min);
}
