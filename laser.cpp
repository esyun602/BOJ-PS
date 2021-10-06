#include<bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int cnt=0;
    int curved;
    char board[100][100];
    int Visit[100][100];
    int rvisited[100][100][4];
    int w, h;
    int start=1;
	int secondi;
    int secondj;

int bfs(int a, int b)
{
    queue<pair<pair<int, int>, pair<int, int> > > Q;
    for (int i = 0; i < 4; i++)
    {
        Q.push(make_pair(make_pair(a, b), make_pair(i, 0)));
    }
    Visit[a][b] = 0;
 
    while (Q.empty() == 0)
    {
        int x = Q.front().first.first;
        int y = Q.front().first.second;
        int Dir = Q.front().second.first;
        int Cnt = Q.front().second.second;
        Q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nCnt = Cnt;
 
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] == '*') continue;
            if (Dir != i) nCnt = nCnt + 1;
            if (Visit[nx][ny] >= nCnt)
            {
                Visit[nx][ny] = nCnt;
                Q.push(make_pair(make_pair(nx, ny), make_pair(i, nCnt)));
            }
        }
    }
    return Visit[secondi][secondj];
}


int main(){
    int firsti=-1;
    int firstj;
    
    scanf("%d %d", &w, &h);
    getchar();
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%c", &board[i][j]);
        }
        getchar();
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
        	Visit[i][j] = ~(1<<31);
            if(board[i][j]=='*'){
            	for(int k=0;k<4;k++)
                rvisited[i][j][k]=true;
            }
            if(board[i][j] == 'C' && firsti==-1){
                firsti = i;
                firstj = j;
            }
            else if(board[i][j] == 'C'){
            	secondi = i;
            	secondj = j;
			}
        }
    }
    printf("%d", bfs(firsti, firstj));
}
