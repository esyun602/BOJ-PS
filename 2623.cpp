#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> v(n+1);
    vector<int> ret;
    vector<int> parent(n+1,0);
    stack<int> q;
    for(int i=0;i<m;i++){
        vector<int> tmp;
        int k=0;
        cin>>k;
        for(int j=0;j<k;j++){
            int a;
            cin>>a;
            tmp.push_back(a);
        }
        for(int j=0;j<k-1;j++){
            v[tmp[j]].push_back(tmp[j+1]);
            parent[tmp[j+1]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(parent[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int here = q.top();
        q.pop();
        ret.push_back(here);
        for(int i : v[here]){
            if(--parent[i] == 0){
                q.push(i);
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(parent[i]!=0){
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<ret.size();i++){
        cout<<ret[i]<<"\n";
    }
    
}