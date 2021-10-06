#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef struct uf{
    vector<int> parent;
    uf(int n) : parent(n){
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find(int n){
        if(parent[n] == n)  
			return n;
        return parent[n] = find(parent[n]);
    }

    bool merge(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b)    return false;
        parent[b] = a;
        return true;
    }
}uf;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long ret=0;
    cin>>n;
    uf unionfind(n);
    vector<pii> x(n);
    vector<pii> y(n);
    vector<pii> z(n);
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int,pii>>> pq;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        x[i] = {a,i};
        y[i] = {b,i};
        z[i] = {c,i};
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());
    for(int i=0;i<n-1;i++){
        pq.push({abs(x[i].first-x[i+1].first), {x[i].second, x[i+1].second}});
        pq.push({abs(y[i].first-y[i+1].first), {y[i].second, y[i+1].second}});
        pq.push({abs(z[i].first-z[i+1].first), {z[i].second, z[i+1].second}});
	}
    while(!pq.empty()){
        pair<int,pii> tmp = pq.top();
        pq.pop();
        if(unionfind.merge(tmp.second.first, tmp.second.second)){
            ret += tmp.first;
        }
    }
    cout<<ret;
}
