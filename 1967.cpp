#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bool visited[10001] = {};
int n;
vector<vector<pii> > adj;
int findmax(int now, int* leaf){
    visited[now] = 1;
    int ret=0;
    int nowLeaf = -1;
    int maxv = -1;
    for(pii& i : adj[now]){
        if(visited[i.second])   continue;
        maxv = findmax(i.second, &nowLeaf);
        if(ret<i.first + maxv){
            ret = i.first + maxv;
            *leaf = nowLeaf;
        }
    }
    if(adj[now].size() == 1 && now != 1){
        *leaf = now;
    }
    return ret;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    int start = 1;
    adj.resize(n+1);
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=0;i<n-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    findmax(start,&start);
    memset(visited,0,sizeof(visited));
    cout<<findmax(start,&start);
}