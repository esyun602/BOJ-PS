#include<bits/stdc++.h>
using namespace std;

int t;
int k;
int tmp;
int mini = ~(1<<31);
void show(vector<int> v){
    n = v.size();
    for(int i=0;i<n;i++)
        printf("%d ", v[i]);
    printf("\n");
    
}
int main(){
	vector<int> now;
	vector<int> arr;
	queue<vector<int> > q;
	map<vector<int>, int> cost;
    scanf("%d", &t);
    while(t--){
    	arr.resize(0);
        scanf("%d", &k);
        for(int i=0;i<k;i++){
        	scanf("%d", &tmp);
        	arr.push_back(tmp);
		}
		cost[arr] = 0;
		q.push(arr);
		while(!q.empty()){
			now = q.front();
			q.pop();
			if(now.size() == 1){
				mini = min(mini, now[0]); 
			}
			
			for(int i=0;i<now.size()-1;i++){
				arr.resize(0);
				for(int j=0;j<i;j++){
					arr.push_back(now[j]);
				}
				arr.push_back(now[i]+now[i+1]);
				for(int j=i+1;j<k-1;j++){
					arr.push_back(now[j+1]);
				}
				if(cost.count(arr)==0){
					cost[arr] = cost[now]+now[i]+now[i+1];
					q.push(arr);
				}
			}
		}
		printf("%d\n", mini);
        }
    }
