#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    vector<vector<pair<int,int> > > adj(n+10);
    vector<vector<pair<int,int> > > adj2(n+10);
    vector<bool> visited(n+10,0);
    vector<bool> visited2(n+10,0);
    vector<int> d(n+10, 0xffff);
    vector<int> d2(n+10, 0xffff);
    d[x] = d2[x] = 0;
    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    priority_queue< pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq2;
    for(int i=1;i<=m;i++){
        int a,b, c;
        scanf("%d %d %d", &a, &b, &c);
        adj[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }
    pq.push({d[x],x});
    pq2.push({d2[x],x});
    
    for(int i=0;i<n-1;i++){
        pair<int,int> tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]){
            i--;
            continue;
        }
        visited[tmp.second]=true;
        for(int j=0;j<adj[tmp.second].size();j++){
            if(d[adj[tmp.second][j].first] > d[tmp.second] + adj[tmp.second][j].second){
                d[adj[tmp.second][j].first] = d[tmp.second] + adj[tmp.second][j].second;
                pq.push({d[adj[tmp.second][j].first], adj[tmp.second][j].first});
            }
        }
    }


    for(int i=0;i<n-1;i++){
        pair<int,int> tmp = pq2.top();
        pq2.pop();
        if(visited2[tmp.second]){
            i--;
            continue;
        }
        visited2[tmp.second]=true;
        for(int j=0;j<adj2[tmp.second].size();j++){
            if(d2[adj2[tmp.second][j].first] > d2[tmp.second] + adj2[tmp.second][j].second){
                d2[adj2[tmp.second][j].first] = d2[tmp.second] + adj2[tmp.second][j].second;
                pq2.push({d2[adj2[tmp.second][j].first], adj2[tmp.second][j].first});
            }
        }
    }

    int maxi = -1;
    for(int i=1;i<=n;i++){
        maxi = max(maxi, d[i]+d2[i]);
    }
    printf("%d", maxi);
}
