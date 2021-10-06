#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int v,e;
    long long val=0;
    cin >> v >> e;
    int visited[10005] = {};
    vector<vector<pii> > adj(10005);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
        adj[b].push_back({c,a});
    }
    pq.push({0, 1});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = true;
        val += tmp.first;
        for(auto& i : adj[tmp.second]){
            pq.push(i);
        }
    }
    cout << val;

}