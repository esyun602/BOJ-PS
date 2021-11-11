#include<bits/stdc++.h>
using namespace std;
int visited[10001];
stack<int> s;
typedef struct uf{
    vector<int> parent;
    uf(int n) : parent(n){
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
    }
    int find(int v){
        if(parent[v] == v)  return v;
        return parent[v] = find(parent[v]);
    }
    void unify(int u, int v){
        int a = find(u), b = find(v);
        parent[b] = a;
    }
}uf;

void dfs(int v, vector<vector<int>>&adj, uf &unionfind){
    visited[v] = 1;
    for(int i=0;i<adj[v].size();i++){
        int next = adj[v][i];
        if(visited[next] == 1){
            visited[v] = 2;
            while(s.top() != next){
                unionfind.unify(v,s.top());
                visited[s.top()] = 2;
                s.pop();
            }
            unionfind.unify(v,s.top());
            visited[s.top()] = 2;
            s.pop();
        }
        else if(visited[next]==2){
            int cycle = unionfind.find(next);
            stack<int> s2(s);
            while(!s2.empty()){
                if(unionfind.find(s2.top()) == cycle){
                    break;
                }
                s2.pop();
            }
            if(!s2.empty()){
                visited[v] = 2;
                while(unionfind.find(s.top()) != cycle){
                    unionfind.unify(v,s.top());
                    visited[s.top()]=2;
                    s.pop();
                }
                unionfind.unify(s.top(), v);
                visited[s.top()]=2;
                s.pop();
            }
        }
        else if(visited[next]!=3){
            s.push(v);
            dfs(next,adj,unionfind);
            if(!s.empty()&&s.top()==v)
                s.pop();
        }
    }
    if(visited[v]==1)
        visited[v] = 3;
}


int main(){
    ofstream out("./res1.txt");
    int v,e;
    cin>>v>>e;
    vector<vector<int>> adj(v+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        if(a==b) continue;
        adj[a].push_back(b);
    }
    uf unionfind(v+1);
    for(int i=1;i<=v;i++){
        if(visited[i])
            continue;
        dfs(i,adj,unionfind);
    }
    memset(visited,0,sizeof(visited));
    int cnt=0;

    for(int i=1;i<=v;i++){
        if(visited[i])
            continue;
        cnt++;
        int tmp = unionfind.find(i);
        for(int j=i;j<=v;j++){
            int tmp2 = unionfind.find(j);
            if(tmp2 == tmp){
                visited[j]=1;
            }
        }
    }
    out<<cnt<<'\n';
    memset(visited,0,sizeof(visited));
    for(int i=1;i<=v;i++){
        if(visited[i])
            continue;
        int tmp = unionfind.find(i);
        for(int j=i;j<=v;j++){
            int tmp2 = unionfind.find(j);
            if(tmp2 == tmp){
                visited[j]=1;
                out<<j<<' ';
            }
        }
        out<<-1<<'\n';
    }
    
}
