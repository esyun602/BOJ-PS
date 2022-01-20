#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

void scc(int now, vector<vector<int>> &components, vector<bool> &visited, vector<vector<int>> &adj, vector<vector<int>> &rev, bool reverse, int sccNow, stack<int> &s){
    visited[now] = true;
    if(!reverse){
        for(int& i : adj[now]){
            if(visited[i])  continue;
            scc(i,components,visited,adj,rev,reverse,sccNow,s);
        }
        s.push(now);
    }
    else{
        components[sccNow].push_back(now);
        for(int& i : rev[now]){
            if(visited[i])  continue;
            scc(i,components,visited,adj,rev,reverse,sccNow,s);
        }
    }

}


void solve(int n, int m){
    vector<vector<int>> adj(2*n+1);
    vector<vector<int>> rev(2*n+1);
    vector<vector<int>> components;
    vector<bool> visited(2*n+1);
    stack<int> s;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b; // not: 2*n+1-var
        adj[(a*-1+2*n+1)%(2*n+1)].push_back((b+2*n+1)%(2*n+1));
        adj[(b*-1+2*n+1)%(2*n+1)].push_back((a+(2*n+1))%(2*n+1));
        rev[(b+2*n+1)%(2*n+1)].push_back((a*-1+2*n+1)%(2*n+1));
        rev[(a+(2*n+1))%(2*n+1)].push_back((b*-1+2*n+1)%(2*n+1));
        
    }
    adj[2*n].push_back(1);
    rev[1].push_back(2*n);
    for(int i=1;i<=2*n;i++){
        if(!visited[i]){
            scc(i,components,visited,adj,rev,false,-1,s);
        }
    }
    
    visited = vector<bool>(2*n+1);
    int now = -1;
    while(!s.empty()){
        if(visited[s.top()]){
            s.pop();
            continue;
        }
        now++;
        components.push_back(vector<int>());
        scc(s.top(),components,visited,adj,rev,true,now,s);
        s.pop();
    }/*
    for(auto& i:components){
        for(auto j : i){
            cout<<j<<' ';
        }
        cout<<'\n';
    }*/
    for(vector<int>& i : components){
        visited = vector<bool>(2*n+1);
        for(int& j : i){
            visited[j]=true;
            if(visited[2*n+1-j]==true){
                //cout<<j;
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