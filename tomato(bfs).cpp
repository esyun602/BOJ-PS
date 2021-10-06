#include<bits/stdc++.h>
#define seg cur/m+dy[i]>-1 && cur%m + dx[i] >-1 &&cur/m+dy[i]<n && cur%m + dx[i] <m
using namespace std;

int day[1000][1000];
int cnt=0;
int box[1000][1000];
int visited[1000000];
int m, n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void bfs(){
	int cur;
	int start = 1;
    queue<int> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(box[i][j] == 1){
				q.push(i*m+j);
				day[i][j] = 1;
			}
		}
	}
    while(!q.empty()){
        cur = q.front();
        visited[cur] = 1;
        for(int i=0;i<4;i++){
            if( box[cur/m][cur%m] == 1 && seg){
            	if(box[cur/m+dy[i]][cur%m+dx[i]] == -1)
            		continue;
            	box[cur/m+dy[i]][cur%m+dx[i]] = 1;
            	if(day[cur/m+dy[i]][cur%m+dx[i]] == 0)
            		day[cur/m+dy[i]][cur%m+dx[i]] = day[cur/m][cur%m] +1;
			}       
        }
        q.pop();
        for(int i=0;i<4;i++)
          	 if( seg &&!visited[cur + dy[i] * m + dx[i]] && box[cur/m+dy[i]][cur%m+dx[i]]){
               q.push(cur + dy[i] * m + dx[i]);
               visited[cur + dy[i] * m + dx[i]] =1;
           	}   
    }
	

    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++){
    		if(box[i][j] == 0){
    			printf("-1");
    			return;
			}
			cnt = max(cnt, day[i][j]);
		}
	printf("%d", cnt-1);
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d", &box[i][j]);
    bfs();
}
