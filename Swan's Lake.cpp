#include<bits/stdc++.h>
#define seg (tmp.first+di[i] >= r || tmp.second+dj[i] >= c || tmp.first+di[i]<0 || tmp.second+dj[i]<0)
#define seg2 (tmp2.first+di[i] >= r || tmp2.second+dj[i] >= c || tmp2.first+di[i]<0 || tmp2.second+dj[i]<0)



using namespace std;
int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};
int day [1500][1500];
char board[1500][1500];
bool visited[1500][1500];
bool visited2[1500][1500];
pair<int, int> swan[2];
int s;
queue<pair<int, int> > q;
queue<pair<int, int> > q2;
queue<pair<int, int> > ns;
pair<int, int> tmp;
pair<int, int> tmp2;
int m=0;
int oday;
int c,r;
bool bfs(int ni, int nj);

void showboard(){
	printf("\n");
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    scanf("%d %d", &r, &c);
    getchar();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++){
            scanf("%c", &board[i][j]);
            if(board[i][j] == 'L'){
                swan[s].first = i;
                swan[s++].second = j;
            }
        }
        getchar();
    }
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(board[i][j] == '.' || board[i][j] == 'L')
                for(int k=0;k<4;k++)
                    if(board[i+di[k]][j+dj[k]] == 'X'){
                        tmp.first = i+di[k]; tmp.second = j+dj[k];
                        q.push(tmp);
                        day[tmp.first][tmp.second] = 1;
                        visited2[tmp.first][tmp.second] = true;
                    }

    while(!q.empty()){
        tmp = q.front();
        q.pop();
        
        if(day[tmp.first][tmp.second]>oday){
            oday = day[tmp.first][tmp.second];
            board[swan[0].first][swan[0].second] = '.';
            if(bfs(swan[0].first, swan[0].second)){
                printf("%d", oday-1);
                return 0;
            }
            board[swan[0].first][swan[0].second] = 'L';
        }
        
        board[tmp.first][tmp.second] = '.';
        for(int i=0;i<4;i++){
            if(!seg && board[tmp.first+di[i]][tmp.second+dj[i]] =='X' && !visited2[tmp.first+di[i]][tmp.second+dj[i]] ){
                q.push(make_pair(tmp.first+di[i], tmp.second+dj[i]));   
				visited2[tmp.first+di[i]][tmp.second+dj[i]] = true;
                day[tmp.first+di[i]][tmp.second+dj[i]] = day[tmp.first][tmp.second]+1;
            }
        }
    }
    if(bfs(swan[0].first, swan[0].second)){
                printf("%d", oday);
                return 0;
            }
}

bool bfs(int ni, int nj){
	ns.push({ni,nj});
	visited[ni][nj] = true;
	swap(q2, ns);
	while(!q2.empty()){
		tmp2 = q2.front();
		
		q2.pop();
		if(board[tmp2.first][tmp2.second] == 'L')
			return true;
		for(int i=0;i<4;i++){
		if(!seg2  && !visited[tmp2.first+di[i]][tmp2.second+dj[i]]){
			if(board[tmp2.first+di[i]][tmp2.second+dj[i]] == 'X'){
				ns.push(make_pair(tmp2.first+di[i], tmp2.second+dj[i]));
			}				
			else{
			q2.push(make_pair(tmp2.first+di[i],tmp2.second+dj[i]));
			
			}
			visited[tmp2.first+di[i]][tmp2.second+dj[i]] = true;
		}
	}
	}
	return false;
}

