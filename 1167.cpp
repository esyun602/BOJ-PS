#include<bits/stdc++.h>
using namespace std;
vector<int> vis;
//
//pivot 알고리즘 
//트리의지름 
int dfs(int now, vector<vector<pair<int,int> > >& adj, int*m){
    vis[now]=1;
    int most=0;
    int sec=0;
    int cnt=0;
    for(int i=0;i<adj[now].size();i++){
        if(!vis[adj[now][i].first]){
            int tmp = dfs(adj[now][i].first, adj,m)+adj[now][i].second;
            if(most<=tmp){
                sec = most;
                most = tmp;
            }
            else if(tmp>=sec)
            	sec = tmp;
            cnt++;
        }
    }
    if(cnt==0)  return 0;
    *m=max(most+sec,*m);
    return most;
}

int main(){
    int v,n,m=0,c;
    int M=-1;
    cin >> v;
    vector<vector<pair<int,int> > > adj(v+10);
    vis.resize(v+10);
    fill(vis.begin(),vis.end(),0);
    while(v--){
        cin>>n;
        while(1){
            cin>>m;
            if(m==-1)   break;
            cin>>c;
            adj[n].push_back({m,c});
        }
    }
    dfs(1,adj,&M);
    cout<<M;

}
