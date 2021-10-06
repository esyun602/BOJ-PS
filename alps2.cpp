#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int x;
	int y;
	int p;
}r;
int N;
r * room;
int max=0;
int g=0;
int b(int now)
{
	if(g==0)
	{
		g=room[now].p;
	}
	if(max<g)
		max=g;
	for(int i=now+1;i<N;i++)
	{
		if(room[now].x==room[i].x)
			if(room[now].y-room[i].y<2&&room[now].y-room[i].y>-2)
			{	//printf("%d\n", g);
				g+=room[i].p;	
				b(i);
			
			}
		if(room[now].y==room[i].y)
			if(room[now].x-room[i].x<2&&room[now].x-room[i].x>-2)
			{	//printf("%d\n", g);
				g+=room[i].p;
				b(i);
			
			}	
	}
}
int main()
{
	scanf("%d", &N);
	room = (r*)malloc(sizeof(r)*N);
	for(int j=0;j<N;j++)
		scanf("%d %d %d", &room[j].x, &room[j].y, &room[j].p);
	for(int i=0;i<N;i++)
	{
		g=0;
		b(i);
	}
	printf("%d",max);
}
