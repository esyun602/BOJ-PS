#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dp[10001];
int s,e;
pii findLongest(int v, vector<vector<pii>>&adj){
    if(dp[v] !=0 || e==v){
        return {dp[v],0};
    }
    int ret=0;
    int numRoad = 0;
    for(pii& i : adj[v]){
        pii tmp = findLongest(i.second,adj);
        int val = tmp.first+i.first;
        if(ret<val){
            ret = val;
            numRoad = tmp.second+1;
        }
        else if(ret==val){
            numRoad += tmp.second+1;
        }
    }
    dp[v]=ret;
    return {ret,numRoad};
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pii>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({c,b});
    }
    cin>>s>>e;
    pii tmp = findLongest(s,adj);
    cout<<tmp.first<<'\n'<<tmp.second;
}