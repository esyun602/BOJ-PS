#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int> > adj(n);
    vector<int> parent(n,0);
    queue<int> q;
    vector<int> ans;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        parent[b]++;
    }
    for(int i=0;i<n;i++){
        if(parent[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        ans.push_back(tmp);
        for(int i : adj[tmp]){
            parent[i]--;
            if(parent[i]==0)
                q.push(i);
        }

    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]+1<<' ';
    }
    
}