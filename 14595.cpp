#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, m;
    int ret=0;
    scanf("%d %d", &n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i] = i;
    vector<pair<int, int> > q;
    for(int i=0;i<m;i++){
        int x, y;
        scanf("%d %d",&x, &y);
        q.push_back({x-1,y-1});
    }
    sort(q.begin(),q.end());
    if(m==0){
    	printf("%d", n);
    	return 0;
	}
    int x = q[0].first;
    int y = q[0].second;
    ret += x;
    for(int i=0;i<q.size();i++){
    	while(y>=q[i+1].first && i+1<q.size()){
    		i++;
    		y = max(y,q[i].second);
		}
		if(i+1<q.size()){
			x = q[i+1].first;
			ret += x-y;
			y = q[i+1].second;
		}
		else{
			for(int j=y;j<n;j++)	ret++;
		}
	}
	printf("%d", ret);
}
