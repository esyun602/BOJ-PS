#include<bits/stdc++.h>

using namespace std;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
bool visited[50][50];

void dfs(int arr[][50], int curi, int curj){
	if(visited[curi][curj] || arr[curi][curj] == 0)
		return;
	visited[curi][curj] = true;
	for(int i=0;i<4;i++){
		if(curi+di[i] >-1 && curi+di[i]<50 && curj+dj[i] > -1 && curj+dj[i] < 50)
			dfs(arr, curi+di[i], curj+dj[i]);	
	}
}

int main(){
	int t;
	int n, m, k;
	int a, b;
	int count;
	int arr[50][50] ={};
	scanf("%d", &t);
	for(int i=0;i<t;i++){
		scanf("%d %d", &m, &n);
		for(int j=0;j<n;j++)
			for(int l=0;l<m;l++){
				arr[j][l] =0;
				visited[j][l] = 0;
			}
		scanf("%d", &k);
		for(int l=0;l<k;l++){
			scanf("%d %d", &a, &b);
			arr[b][a] = 1;
		}
		for(int c=0;c<n;c++)
			for(int d=0;d<m;d++){
			//	printf("	%d %d, %d, %d\n", c, d, visited[0][4], arr[c][d]);
				if(!visited[c][d] && arr[c][d]==1){
					//printf(" %d %d\n", c, d);
					count++;
					dfs(arr, c,d);
				}
			}
		printf("%d\n", count);
		count =0;
	}
}
