#include<bits/stdc++.h>
using namespace std;
int cnt;
int visited[10]; 
int n;
int w[10][10];
int mini = ~(1<<31);
void dfs(int cur){
    if(visited[cur]){
        for(int i=0;i<n;i++){
        	if(!visited[i])
        		break;
        	if(i == n-1 && cur ==0)
        	{
        		//printf("cur: %d mini: %d, cnt: %d\n", cur, mini, cnt+ w[cur][0]);
        		mini = min(cnt , mini);
        	}
		}
		return;
    }
    visited[cur]= 1;
    for(int i=0;i<n;i++){
        if(w[cur][i]!=0){
        	cnt += w[cur][i];
        	//if(!visited[i])
			//	printf("%d -> %d\n", cur, i);
			dfs(i);
			cnt -= w[cur][i];
		}
    }
    visited[cur] =0;
}

int main(){
    int tp;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &w[i][j]);
    dfs(0);
    printf("%d", mini);
}
