#include<bits/stdc++.h>
using namespace std;
int visited[805];
typedef pair<int,int> pii;
int main(){
    vector<int> d(805, 0xfffffff);
    vector<int> d2(805, 0xfffffff);
    vector<int> d3(805, 0xfffffff);
    int n,e;
    cin >> n >> e;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<vector<pii> > graph(805);
    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({c,b});
        graph[b].push_back({c,a});
    }
    int a,b;
    cin >> a >> b;
    d[1] = 0;
    pq.push({d[1],1});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second])  continue;
        visited[tmp.second] = true;
        for(auto &i : graph[tmp.second]){
            if(i.first+d[tmp.second] < d[i.second]){
                d[i.second] = i.first + d[tmp.second];
                pq.push({d[i.second], i.second});
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    d2[a] = 0;
    pq.push({d2[a], a});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second])  continue;
        visited[tmp.second] = true;
        for(auto &i : graph[tmp.second]){
            if(i.first+d2[tmp.second ]< d2[i.second]){
                d2[i.second] = i.first + d2[tmp.second];
                pq.push({d2[i.second], i.second});
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    d3[n] = 0;
    pq.push({d3[n], n});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second])  continue;
        visited[tmp.second] = true;
        for(auto &i : graph[tmp.second]){
            if(i.first+d3[tmp.second ]< d3[i.second]){
                d3[i.second] = i.first + d3[tmp.second];
                pq.push({d3[i.second], i.second});
            }
        }
    }
    int ret = min(d[a] + d2[b] + d3[b], d[b] + d2[b] + d3[a]);
    if(ret >= 0xfffffff) ret = -1;
    printf("%d", ret);
}
