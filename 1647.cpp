#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int cost = 0;
    int n,m;
    int maxv=-1;
    cin>>n>>m;
    vector<vector<pii> > adj(n);
    int visited[100005]={};
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    visited[0]=1;
    for(pii& i : adj[0]){
        pq.push(i);
    }
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = true;
        maxv = max(maxv, tmp.first);
        cost += tmp.first;
        for(pii& i : adj[tmp.second]){
            if(!visited[i.second]){
                pq.push(i);
            }
        }
    }
    cout<<cost-maxv;
}