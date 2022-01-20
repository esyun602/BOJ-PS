#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void scc(int now, vector<vector<int>> &components, vector<bool> &visited, vector<vector<int>> &adj, vector<vector<int>> &rev, bool reverse, int sccNow, stack<int> &s){
    visited[now] = true;
    if(!reverse){
        s.push(now);
        for(int& i : adj[now]){
            if(visited[i])  continue;
            scc(i,components,visited,adj,rev,reverse,sccNow,s);
        }
    }
    else{
        for(int& i : rev[now]){
            if(visited[i])  continue;
            components[sccNow].push_back(now);
            scc(i,components,visited,adj,rev,reverse,sccNow,s);
        }
    }

}

void dfsFor1(int now, vector<vector<int>> &components, vector<bool> &visited, vector<vector<int>> &adj){
    components[0].push_back(now);
    visited[now]=true;
    for(int& i : adj[now]){
        if(visited[i])  continue;
        dfsFor1(i,components,visited,adj);
    }
}

void solve(int n, int m){

    vector<bool> var(n*2+1);
    vector<vector<int>> adj(2*n+1);
    vector<vector<int>> rev(2*n+1);
    vector<vector<int>> components;
    vector<bool> visited(2*n+1);
    stack<int> s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b; // not: 2*n-var
        a*=-1;
        if(a<0) a+=2*n+1;
        if(b<0) b+=2*n+1;
        adj[a].push_back(b);
        rev[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            scc(i,components,visited,adj,rev,false,-1,s);
        }
    }
    
    visited = vector<bool>(2*n+1);
    components.push_back(vector<int>());
    dfsFor1(1,components,visited,adj);
    int now = 0;
    while(!s.empty()){
        if(visited[s.top()]){
            s.pop();
            continue;
        }
        now++;
        components.push_back(vector<int>());
        scc(s.top(),components,visited,adj,rev,true,now,s);
        s.pop();
    }
    visited = vector<bool>(2*n+1);
    for(vector<int>& i : components){
        for(int& j : i){
            visited[j]=true;
            if(visited[2*n+1-j]==true){
                cout<<"no\n";
                return;
            }
        }
    }
    cout<<"yes\n";
}

int main(){
    int n,m;
    while(scanf("%d %d", &n,&m)!=EOF){
        solve(n,m);
    }
    
}