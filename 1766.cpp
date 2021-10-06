#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    vector<int> solution;
    vector<int> parent(n+1);
    parent[0]=-1;
    priority_queue<int, vector<int>, greater<int> > pq;
    vector<vector<int> > v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        parent[b]++;
    }
    for(int i=0;i<n+1;i++){
        if(!parent[i]) pq.push(i);
    }
    while(!pq.empty()){
        int tmp = pq.top();
        pq.pop();
        solution.push_back(tmp);
        for(int i : v[tmp]){
            parent[i]--;
            if(!parent[i]){
                pq.push(i);
            }
        }
    }
    for(int i=0;i<solution.size();i++){
        cout<<solution[i]<<' ';
    }
}