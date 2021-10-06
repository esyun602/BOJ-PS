#include<bits/stdc++.h>
using namespace std;
int di[4] = {0,-1,0,1};
int dj[4] = {-1,0,1,0};
int r,c;


int dfs(vector<vector<int> >& board, vector<int>& visited, int i, int j, int lev){
    static int maxlen =0;
    visited[board[i][j]] = 1;
    for(int k=0;k<4;k++){
        int nexti = i+di[k];
        int nextj = j+dj[k];
        if(nexti>=0 && nexti<r && nextj>=0 && nextj<c){
            if(!visited[board[nexti][nextj]]){
                dfs(board, visited, nexti, nextj, lev+1);
            }
        }
    }
    visited[board[i][j]] = 0;
    maxlen = max(maxlen, lev);
    if(lev==1)  return maxlen;
}


int main(){
    cin>>r>>c;
    vector<int> visited(26,0);
    vector<vector<int> > board(r,vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char a;
            cin>>a;
            board[i][j] = a-'A';
        }
    }
    cout<<dfs(board,visited, 0,0, 1);

}