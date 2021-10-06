#include<bits/stdc++.h>
using namespace std;




int main(){
	int n;
	int d;
	int tmp;
	priority_queue<int, vector<int>, less<int> > maxh;
	priority_queue<int, vector<int>, greater<int> >minh;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &d);
		if(!maxh.empty() && d>= maxh.top()){
			minh.push(d);
		}
		else
			maxh.push(d);
		if(minh.size()>maxh.size()){
			tmp = minh.top();
			minh.pop();
			maxh.push(tmp);
		}
		else if(maxh.size() == minh.size()+2){
			tmp = maxh.top();
			maxh.pop();
			minh.push(tmp);
		}
		printf("%d\n", maxh.top());
	}
}
