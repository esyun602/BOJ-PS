#include<bits/stdc++.h>
#define CASE1 ((i+a)>=n || (j+a)>=n)
#define CASE2 (i+a>=n || j-a<0)

using namespace std;
typedef pair<int,int> pii;
int n;
queue<int> q2;
void fillBoard(vector<vector<int> >& v, int i, int j, queue<pii> &q){
    int a=1;
    while( !CASE1 || !CASE2 ){
        if(!CASE1){
            if(v[i+a][j+a]==1)
                q.push({i+a,j+a});
            v[i+a][j+a] = 0;
        }
        if(!CASE2){
            if(v[i+a][j-a]==1)
                q.push({i+a,j-a});
            v[i+a][j-a] = 0;
        }
        a++;
    }
}
void eraseBoard(vector<vector<int> > &v, queue<pii> &q){
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        v[tmp.first][tmp.second]=1;
    }
}

int findMax(vector<vector<int> > &v, int lev){
    if(lev >= n*n){
        return 0;
    }
    int nextlev;
    if(n%2==0){
    		if(lev%n==n-1){
    			nextlev = lev+1;
			}
			else if(lev%n==n-2){
				nextlev = lev+3;
			}
			else nextlev = lev+2;
	}
	else{
		nextlev = lev+2;
	}
    if(v[lev/n][lev%n]==0){
    	return findMax(v,nextlev);
    }
    queue<pii> q;
    int ret1 = findMax(v, nextlev);
    fillBoard(v,lev/n, lev%n, q);
    int ret2 = findMax(v, nextlev);
    eraseBoard(v, q);
    return max(ret1, ret2+1);
}




int main(){
    cin>> n;
    vector<vector<int> > v(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    cout<<findMax(v, 0)+findMax(v,1);
}
