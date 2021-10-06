#include<bits/stdc++.h>

int a(int a, int b){
	return a<b;
}
using namespace std;
int main(){
	int cnt=0;
    int n;
    int e= 0;
    scanf("%d", &n);
    vector<pair<int, int> > time(n);
    for(int i=0;i<n;i++){
        scanf("%d %d", &time[i].second, &time[i].first);
    }
    sort(time.begin(), time.end());
    for(int i=0;i<n;i++){
    	if(e>time[i].second)
    		continue;
    	e = time[i].first;
    	cnt++;
	}
	printf("%d", cnt);
}
