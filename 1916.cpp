#include<bits/stdc++.h>
#define INF 0x3FFFFFFF
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pii> > adj(n+1);
    vector<int> d(n+1, INF);
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<bool> visited(n+1, false);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d", &a,&b,&c);
        adj[a].push_back({c,b});
    }
    int start,end;
    scanf("%d %d", &start, &end);
    d[start] = 0;
    pq.push({d[start], start});
    while(!pq.empty()){
        pii tmp = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = true;
        for(pii& i : adj[tmp.second]){
            if(d[i.second] > tmp.first + i.first){
                d[i.second] = tmp.first + i.first;
                pq.push({d[i.second], i.second});
            }
        }
    }
    cout<<d[end];
}   
