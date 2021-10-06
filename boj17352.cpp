#include<bits/stdc++.h>
using namespace std;

int visited[300000];
vector<vector<int> > adj;

void dfs(int now){
	visited[now] = 1;
	for(int i=0;i<adj[now].size();i++){
		if(visited[adj[now][i]])
			continue;
		dfs(adj[now][i]);
	}
}


int main(){
	int n;
	int a, b;
	scanf("%d", &n);
	adj.resize(n);
	for(int i=0;i<n-2;i++){
		scanf("%d %d", &a, &b);
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	if(adj[0].size()==0){
		printf("1 2");
	}
	else{
		dfs(0);
		for(int i=0;i<n;i++){
			if(!visited[i]){
				printf("1 %d", i+1);
				return 0;
			}
		}
	}
	
}
