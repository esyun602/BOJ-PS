#include<bits/stdc++.h>
#define INF 0xfffffff
using namespace std;

typedef struct unionfind{
    vector<int> parent, rank;
    unionfind(int n) : parent(n), rank(n, 1){
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    int find(int u){
        if(u==parent[u])
            return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v){
        u = find(u); v = find(v);
        if(u==v)    return;
        if(rank[u] > rank[v]) swap(u,v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
}unionfind;


int water[300] = {};


int main(){
    vector<pair<int, pair<int, int> > > data;
    int n;
    scanf("%d", &n);
    unionfind uf(n);
    for(int i=0;i<n;i++){
        int w;
        scanf("%d", &w);
        data.push_back({w, {i,i}});
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            int w;
            scanf("%d", &w);   
			if(i==j)	continue; 
            data.push_back({w, {i,j}});
        }
    sort(data.begin(), data.end());
    int ret=0;
    for(int i=0;i<data.size();i++){
        int w = data[i].first;
        int start = data[i].second.first;
        int end = data[i].second.second;
        if(start == end && !water[uf.find(start)]){
            water[uf.find(start)] = true;
            ret += w;
        }
        else if((!water[uf.find(start)] || !water[uf.find(end)]) && uf.find(start) != uf.find(end)){
            ret += w;
            if(water[uf.find(start)] || water[uf.find(end)]){
                uf.merge(start, end);
                water[uf.find(start)] = true;
            }
            else{
                uf.merge(start,end);
            }
        }
    }
    printf("%d", ret);
}
