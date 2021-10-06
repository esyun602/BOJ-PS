#include<stdio.h>
#include<stdlib.h>
int **fast;
int d=0;
int N;
int *check;
int **time;
int mask;
int maskmax;
int *im;
int k=0;
/*void backtracking(int start,int now,int distance)
{
	
	check[now]=1;
	d+=distance;
	if(fast[start][now]>d)
		fast[start][now]=d;
	for(int i=0;i<N;i++)
		if(check[i]!=1)
		{
			backtracking(start,i,time[now][i]);
			check[i]=0;
			d-=time[now][i];
		}
}
*/
int brute(int now)
{
    int imc[N];
	for(int i=0;i<N;i++)
		imc[i]=im[i];
	check[now]=1;
	if(im[now]>0)
		mask+=im[now];
	if(maskmax<mask)
		maskmax=mask;
	for(int i=0;i<N;i++)
		if(check[i]!=1)
		{//printf("%d ", now);
		//	for(int j=0;j<N;j++)
		  //  	printf("now:%d i:%d mask:%d maskmax:%d im[%d]:%d\t",now, i,mask, maskmax, j,im[j]);
		   // printf("\n");
			for(int j=0;j<N;j++)
				if(im[j]-fast[now][i]>0)
					im[j]-=fast[now][i];
				else
				{
					im[j]=0;
				}
			brute(i);
			check[i]=0;
			mask-=im[i];
			for(int j=0;j<N;j++)
				im[j]=imc[j];
		}	
		
}



int main()
{
	int M;
	scanf("%d %d", &N, &M);
	
	im = (int*)malloc(sizeof(int)*N); 
	check = (int*)malloc(sizeof(int)*N);
	for(int i=0;i<N;i++)
		check[i]=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d", &im[i]);
	}
	mask=0; 
	maskmax=0;
	int a, b;
	
	
	time = (int**)malloc(sizeof(int*)*N);
	for(int i=0; i<N; i++)
		time[i] = (int*)malloc(sizeof(int)*N);
		
		
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
		{
			if(i==j)
				time[i][i]=0;
			else
				time[i][j]=100000;
		}
	
		
		
	fast = (int**)malloc(sizeof(int*)*N);
	for(int i=0; i<N; i++)
		fast[i] = (int*)malloc(sizeof(int)*N);
		
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			fast[i][j]=1000000;	
///////////////////////////////////
	for(int i=0;i<M;i++)
	{
		scanf("%d %d", &a, &b);
		scanf("%d", &time[a-1][b-1]);
		time[b-1][a-1]=time[a-1][b-1];
		fast[a-1][b-1]=time[a-1][b-1];
		fast[b-1][a-1]=time[a-1][b-1];
	}
////*///////////////////////////////	
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		check[j]=0;
		backtracking(i,i,0);
	}*/
	
	for(int k=0;k<N;k++)
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(fast[i][j]>fast[i][k]+fast[k][j])
					fast[i][j]=fast[i][k]+fast[k][j];
	for(int i=0;i<N;i++)
		check[i]=0;
	brute(0);
/*	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
			printf("%d\t",fast[i][j]);
		printf("\n");
	}
	*/
	printf("%d", maskmax);
	
}
