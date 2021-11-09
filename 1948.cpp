#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[10001];
int visited[10001];
int s,e;
int findLongest(int v, vector<vector<pii>>&adj){
    if(dp[v] !=0 || e==v){
        return dp[v];
    }
    int ret=0;
    for(pii& i : adj[v]){
        int tmp = findLongest(i.second,adj);
        int val = tmp+i.first;
        if(ret<val){
            ret = val;
        }
    }
    dp[v]=ret;
    return ret;
}

int findNumRoad(int v, vector<vector<pii>>&adj){
    int ret=0;
    visited[v] = 1;
    for(pii& i : adj[v]){
        if(dp[v] == dp[i.second]+i.first){
            if(!visited[i.second])
                ret+=findNumRoad(i.second,adj)+1;
            else
                ret+=1;
        }
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    cin>>s>>e;
    int tmp = findLongest(s,adj);
    int tmp2 = findNumRoad(s,adj);
    cout<<tmp<<'\n'<<tmp2;
}