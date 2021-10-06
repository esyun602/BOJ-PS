#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int di[4] = {-1,0,1,0}; // 12시 시작
int dj[4] = {0,1,0,-1};

int main(){
    int board[105][105];
    memset(board, -1, sizeof(board));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>board[i][j];
        }
    }
    bool varied = true;
    int cnt=-1;
    
    while(varied){
    	int visited[105][105] = {};
        int surface[105][105] = {};
    	queue<pii> q;
    	q.push({1,1});
    	while(!q.empty()){
    		pii tmp = q.front();
    		q.pop();
    		for(int i=0;i<4;i++){
    			int next = board[tmp.first+di[i]][tmp.second+dj[i]];
    			if( next !=-1){
    				if(next == 1){
    					surface[tmp.first+di[i]][tmp.second+dj[i]]++; 
					}
                    else if(!visited[tmp.first+di[i]][tmp.second+dj[i]]){
                        visited[tmp.first+di[i]][tmp.second+dj[i]] = 1;
                        q.push({tmp.first+di[i],tmp.second+dj[i]});
                    }
				}
			}
		}
        varied = false;
        cnt++;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(surface[i][j]>=2){
                    varied = true;
                    board[i][j] = 0;
                }
            }
        }
    }
    cout<<cnt;
}
