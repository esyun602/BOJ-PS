#include<iostream>
#include<vector>
using namespace std;

int CalcNum(vector<vector<int>> &v, vector<int> &cnt, vector<bool> &visited, int now=1, bool* early = nullptr){
    bool e=false;
    int ret=0;
    visited[now]=true;
    for(int i=0;i<v[now].size();i++){
        if(!visited[v[now][i]]){
            ret+=CalcNum(v,cnt,visited,v[now][i], &e);
            if(e){
                cnt[now]--;
            }
        }
    }
    if(now!=1 && cnt[now]==1 || now==1 && cnt[now]==0){
        if(early)
            *early=false;
        return ret;
    }
    if(early)
        *early=true;
    return ret+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<vector<int>> v(n+1);
    vector<bool> visited(n+1);
    vector<int> cnt(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        cnt[a]++;
        cnt[b]++;
    }
    cout<<CalcNum(v,cnt,visited);
}