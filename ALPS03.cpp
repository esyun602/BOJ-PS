#include<bits/stdc++.h>
using namespace std;
vector<int> path;
bool found;
vector<vector<int> > arr;
vector<int> visited;

void findpath(int start, int end){
    visited[start] = 1;
    path.push_back(start);
    if(start == end){
        found = true;
        return;
    }
    for(int i=0;i<arr[start].size();i++){
        if(!visited[arr[start][i]]){
            findpath(arr[start][i], end);
            if(found)
                return;
        }
    }
    path.pop_back();
}

int findnum(int start, int ban){
	visited[start] = 1;
	int ret=0;
	for(int i=0;i<arr[start].size();i++){
		if(!visited[arr[start][i]] && ban!=arr[start][i] ){
			ret += findnum(arr[start][i], ban);
		}
	}
	return ret+1;
}

int main(){
    int start, end;
    int n;
    scanf("%d", &n);
    arr.resize(n+1);
    visited.resize(n+1);
    for(int i=0;i<n+1;i++){
    	visited[i]=0;
	}
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d", &a,&b);
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    scanf("%d %d", &start, &end);
    findpath(start, end);
    
    for(int i=0;i<n+1;i++){
    	visited[i]=0;
	}
	
	int a=findnum(start, path[1]);
	
	 for(int i=0;i<n+1;i++){
    	visited[i]=0;
	}
	
	int b=findnum(end,path[path.size()-2]);
	
    printf("%lld", (long long)a*b); 
}
