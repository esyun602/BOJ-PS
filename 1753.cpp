#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int visited[20005];
int main(){
    int v,e;
    cin >> v >> e;
    int k;
    cin >> k;
    vector<int> d(20005, 0xfffffff);
    vector<vector<pii> > graph(20005);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
    }
    d[k] = 0;
    pq.push({d[k], k});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = true;
        for(auto &i : graph[tmp.second]){
            if(d[i.second] > d[tmp.second] + i.first){
                d[i.second] = d[tmp.second] + i.first;
                pq.push({d[i.second], i.second});
            }
        }
    }
    for(int i=1;i<=v;i++){
        printf(d[i] >= 0xfffffff ? "INF\n" : "%d\n", d[i]);
    }
}