#include<bits/stdc++.h>
using namespace std;
int n;
int visited[1001][1001];
vector<pair<int, pair<int, int> > > v;
struct uf{
	vector<int> parent, rank;
	uf(int n) : parent(n+1), rank(n+1,1){
		//1~n: parent, rank
		for(int i=1;i<=n;i++)
			parent[i] = i;
	}
	int find(int u){
		if(parent[u]==u)
			return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v){
		u = find(u), v = find(v);
		if(u==v)
			return;
		if(rank[u]>rank[v])
			swap(u,v);
		parent[u] = parent[v];
		if(rank[u]==rank[v])
			rank[v]++;
	}
};
int main(){
    int tmp;
    int nowi, nowj;
    long long sum=0;
    scanf("%d", &n);
    struct uf set(n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d", &tmp);
            v.push_back(make_pair(tmp, make_pair(i, j)));
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
    	//nowi = 1~n
        nowi = v[i].second.first;
        nowj = v[i].second.second;
        if(set.find(nowi) == set.find(nowj))
        	continue;
        set.merge(nowi, nowj);
        sum += v[i].first;
    }
    printf("%lld", sum);
}
