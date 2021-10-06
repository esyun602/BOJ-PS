#include<bits/stdc++.h>
using namespace std;

struct unionfind{
    vector<int> parent;
    unionfind(int n) : parent(n){
        for(int i=0;i<n;i++)    parent[i] = i;
    }
    int find(int n){
        if(parent[n]==n)    return n;
        return parent[n] = find(parent[n]);
    }
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u==v)    return;
        parent[v] =u;
    }
};


int main(){
    vector<int> v;
    int g, p;
    int i=0;
    scanf("%d%d",&g,&p);
    struct unionfind uf(g);
    for(int i=0;i<p;i++){
        int tmp;
        scanf("%d", &tmp);
        v.push_back(tmp-1);
    }
    vector<int> visited(g,0);
    for(i=0;i<v.size();i++){
        int now = v[i];
        if(!visited[now]){
            visited[now] = 1;
            if(now!=0 && visited[now-1]){
            	uf.merge(now-1, now);
			}
            if(now+1<g && visited[now+1]){
                uf.merge(now, now+1);
            }
        }
        else{
            now = uf.find(now);
            if(now==0){
                printf("%d\n", i);
                return 0;
            }
            visited[now-1] = 1;
            uf.merge(now-1, now);
            if(now-1!=0 && visited[now-2])
            	uf.merge(now-2,now-1);
        } 
    }
    printf("%d\n", i);
}
