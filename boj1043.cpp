#include<bits/stdc++.h>
using namespace std;
vector<int> know(51,0);
vector<int>visited(50,0);
int adj[55][55]={};
int n;
int dfs(int now){
    visited[now]=1;
    int ret = know[now];
    if(know[now]){
        for(int i=0;i<55;i++){
            if(adj[now][i])
                know[i]=1;
        }
    }
    for(int i=1;i<=n;i++){
        if(adj[now][i]==1 && !visited[i]){
        	
            ret |= dfs(i);
        }
    }
    know[now]=ret;
    return ret;
}

int main(){
    int m;
    int cnt=0;
    vector<int> p(50,0);
    scanf("%d %d", &n,&m);
    int num;
    vector<int> f(m,0);
    scanf("%d", &num);
    for(int i=0;i<num;i++){
        int tmp;
        scanf("%d", &tmp);
        know[tmp] = 1;
    }
    for(int i=0;i<m;i++){
    	fill(p.begin(),p.end(),0);
        scanf("%d", &num);
        for(int j=0;j<num;j++){
            int tmp;
            scanf("%d", &tmp);
            p[j]=tmp;
        }
        f[i]=p[0];
        for(int j=0;j<num;j++){
            for(int k=0;k<num;k++){
                adj[p[j]][p[k]]=1;
            }
        }
    }
    for(int i=0;i<55;i++){
		for(int j=0;j<55;j++){
			printf("%d", adj[i][j]);
		}
		printf("\n");
	}
    for(int i=1;i<=n;i++){
        dfs(i);
        fill(visited.begin(),visited.end(),0);
    }
    for(int i=0;i<m;i++){
        if(know[f[i]]) cnt++;
    }
    printf("%d", m-cnt);
}
