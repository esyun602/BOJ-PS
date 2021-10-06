#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> star;
typedef pair<double, int> pid;
double distance(star s1, star s2){
    return sqrt((s1.first-s2.first)*(s1.first-s2.first) + (s1.second-s2.second)*(s1.second-s2.second));
}


int main(){
    int n;
    cin>>n;
    double adj[100][100] = {};
    double ret =0;
    bool visited[100] = {};
    vector<star> v(n);
    priority_queue<pid, vector<pid>, greater<pid>> pq;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            adj[i][j] = adj[j][i] = distance(v[i], v[j]);
        }
    }
    visited[0] = 1;
    for(int i=1;i<n;i++){
        pq.push({adj[0][i], i});
    }
    while(!pq.empty()){
        pid tmp  = pq.top();
        pq.pop();
        if(visited[tmp.second]) continue;
        visited[tmp.second] = 1;
        ret+= tmp.first;
        for(int i=0;i<n;i++){
            if(!visited[i] && i!= tmp.second){
                pq.push({adj[tmp.second][i], i});
            }
        }
    }
    printf("%.2lf", ret);
}