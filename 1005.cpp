#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[1005];

int find(int now, vector<vector<int> >&graph, vector<int>& cost, vector<int>& visited){
    if(dp[now] != -1)
        return dp[now];
    int ret=-1;
    if(graph[now].empty()){
        return cost[now];
    }

    for(int i : graph[now]){
        if(visited[i])  continue;
        visited[i] = true;
        ret = max(ret, find(i, graph, cost, visited));
        visited[i] = false;
    }
    return dp[now] = ret + cost[now];
}


int main(){
    int T;
    cin >> T;
    while(T--){
        memset(dp, -1, sizeof(dp));
        int n,k;
        cin>>n >> k;
        vector<int> cost(n+5);
        vector<int> visited(n+5,0);
        vector<vector<int> > graph(n+5);
        for(int i=1;i<=n;i++){
            cin >> cost[i];
        }
        for(int i=0;i<k;i++){
            int a,b;
            cin >> a >> b;
            graph[b].push_back(a);
        }
        int w;
        cin >> w;
        cout<< find(w, graph, cost, visited) << "\n";
    }
}