#include<bits/stdc++.h>
using namespace std;
typedef pair<long,long> pll;

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        bool ret = false;
        int n,m,w;
        cin >>n>>m>>w;
        vector<vector<pll> > adj(n);
        for(int i=0;i<m;i++){
            long long a,b,c;
            cin>>a>>b>>c;
            adj[--a].push_back({c,--b});
            adj[b].push_back({c,a});
        }
        for(int i=0;i<w;i++){
            long long a,b,c;
            cin>>a>>b>>c;
            adj[--a].push_back({-c,(--b)});
        }

        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i])  continue;
            vector<int> d(n,0xfffffff);
            d[i]=0;
            for(int j=0;j<n && !ret;j++){
                for(int k=0;k<n && !ret;k++){
                    if(d[k]==0xfffffff) continue;
                    visited[k] = 1;
                    for(pll l : adj[k]){
                        if(d[k]+l.first < d[l.second]){
                            d[l.second] = d[k]+l.first;
                            if(j==n-1){
                                ret = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if(ret) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
}
}