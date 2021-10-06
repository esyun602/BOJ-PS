#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n;
vector<pii> parent(40001);
vector<int> d(40001);
vector<int> depth(40001);
vector<vector<pii>> adj(40001);

void dfs(int now, int node, int dir){
    static vector<bool> visited(n+1,0);
    visited[now] = true;
    if(adj[now].size()>2 || now == 1){
        node = now;
        dir = -1;
    }
    int j=1;
    for(pii& i : adj[now]){
        int next = i.second;
        if(visited[next])
            continue;
        parent[next] = {node,dir == -1 ? j : dir};
        d[next] = d[now]+i.first;
        depth[next] = depth[now]+1;
        dfs(next, node, dir==-1 ? j : dir);
        j++;
    }
}

pii findCommonParent(int a,int b){
    vector<int> visited(n+1);
    pii x={a, parent[a].second},y={b, parent[b].second};
    if(x==y)    return {x.first, 0};
    visited[x.first] = parent[x.first].second;
    visited[y.first] = parent[y.first].second;
    while(1){
        pii now;
        if(x.first!=1){
            now = x;
            x = parent[x.first];
            if(visited[x.first]){
                if(visited[x.first] == parent[now.first].second){
                    return {x.first, 0};
                }
                return {x.first,1};
            }
            visited[x.first] = parent[now.first].second; 
        }
        if(y.first!=1){
            now = y;
            y = parent[y.first];
            if(visited[y.first]){
                if(visited[y.first] == parent[now.first].second){
                    return {y.first, 0};
                }
                return {y.first,1};
            }
            visited[y.first] = parent[now.first].second; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    parent[1] = {1,1};
    dfs(1,1,1);
    int m;
    cin>>m;
    while(m-->0){
        int s,e;
        cin>>s>>e;
        pii tmp = findCommonParent(s,e);
        if(tmp.second){
            cout<<d[s]+d[e]-2*d[tmp.first]<<'\n';
        }
        else{
            cout<<abs(d[s]-d[e])<<'\n';
        }
    }
}