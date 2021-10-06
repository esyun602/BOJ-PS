#include<bits/stdc++.h>
using namespace std;
#define LEFT 0
#define UP 1
#define RIGHT 2
#define DOWN 3


int upBound[10][10];
int lowBound[10][10];
int rightBound[10][10];
int leftBound[10][10];

int findv(int lev, int mov, vector<vector<char>>& v, pair<int,int> redPos, pair<int,int> bluePos){
    //printf("REDPOS: %d, %d\n", redPos.first,redPos.second);
    static int minLev = 11;
    lev++;
    if(minLev<=lev){
        return 11;
    }
    switch (mov)
    {
    case LEFT:
        if(redPos.first == bluePos.first && leftBound[redPos.first][redPos.second] == leftBound[bluePos.first][bluePos.second] && redPos.second < bluePos.second){
            if(v[redPos.first][leftBound[redPos.first][redPos.second]] == 'O'){
                return 11;
            }
            redPos.second = leftBound[redPos.first][redPos.second];
            bluePos.second = redPos.second+1;
        }
        else if(redPos.first == bluePos.first &&leftBound[redPos.first][redPos.second] == leftBound[bluePos.first][bluePos.second]){
            bluePos.second = leftBound[bluePos.first][bluePos.second];
            redPos.second = bluePos.second+1;
        }
        else{
            redPos.second = leftBound[redPos.first][redPos.second];
            bluePos.second = leftBound[bluePos.first][bluePos.second];
        }
        break;
    case RIGHT:
        if(redPos.first == bluePos.first && rightBound[redPos.first][redPos.second] == rightBound[bluePos.first][bluePos.second] && redPos.second > bluePos.second){
            if(v[redPos.first][rightBound[redPos.first][redPos.second]] == 'O'){
                return 11;
            }
            redPos.second = rightBound[redPos.first][redPos.second];
            bluePos.second = redPos.second-1;
        }
        else if(redPos.first == bluePos.first &&rightBound[redPos.first][redPos.second] == rightBound[bluePos.first][bluePos.second]){
            bluePos.second = rightBound[bluePos.first][bluePos.second];
            redPos.second = bluePos.second-1;
        }
        else{
            redPos.second = rightBound[redPos.first][redPos.second];
            bluePos.second = rightBound[bluePos.first][bluePos.second];
        }
        break;
    case UP:
        if(redPos.second == bluePos.second && upBound[redPos.first][redPos.second] == upBound[bluePos.first][bluePos.second] && redPos.first < bluePos.first){
            if(v[upBound[redPos.first][redPos.second]][redPos.second] == 'O'){
                return 11;
            }
            redPos.first = upBound[redPos.first][redPos.second];
            bluePos.first = redPos.first+1;
        }
        else if(redPos.second == bluePos.second &&upBound[redPos.first][redPos.second] == upBound[bluePos.first][bluePos.second]){
            bluePos.first = upBound[bluePos.first][bluePos.second];
            redPos.first = bluePos.first+1;
        }
        else{
            redPos.first = upBound[redPos.first][redPos.second];
            bluePos.first = upBound[bluePos.first][bluePos.second];
        }
        break;
    case DOWN:
        if(redPos.second == bluePos.second && lowBound[redPos.first][redPos.second] == lowBound[bluePos.first][bluePos.second] && redPos.first > bluePos.first){
            if(v[lowBound[redPos.first][redPos.second]][redPos.second] == 'O'){
                return 11;
            }
            redPos.first = lowBound[redPos.first][redPos.second];
            bluePos.first = redPos.first-1;
        }
        else if(redPos.second == bluePos.second &&lowBound[redPos.first][redPos.second] == lowBound[bluePos.first][bluePos.second]){
            bluePos.first = lowBound[bluePos.first][bluePos.second];
            redPos.first = bluePos.first-1;
        }
        else{
            redPos.first = lowBound[redPos.first][redPos.second];
            bluePos.first = lowBound[bluePos.first][bluePos.second];
        }
        break;
    default:
        break;
    }
    if(v[redPos.first][redPos.second] == 'O'){
        return lev;
    }
    else if(v[bluePos.first][bluePos.second] == 'O'){
        return 11;
    }
    if(lev==10){
        return 11;
    }
    if(mov != LEFT  && mov != RIGHT){
        minLev = min(minLev, findv(lev, LEFT, v, redPos, bluePos));
        minLev = min(minLev, findv(lev, RIGHT, v, redPos, bluePos));
    }
    if(mov != UP && mov!=DOWN){
        minLev = min(minLev, findv(lev, UP, v, redPos, bluePos));
        minLev = min(minLev, findv(lev, DOWN, v, redPos, bluePos));
    }
    return minLev;
}


int main(){
    int n,m;
    cin>>n>>m;
    getchar();
    vector<vector<char>> board(10, vector<char>(10));
    pair<int,int> redPos;
    pair<int,int> bluePos;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            board[i][j] = getchar();
            if(board[i][j] == 'R'){
                board[i][j] = '.';
                redPos = {i,j};
            }
            else if(board[i][j] == 'B'){
                board[i][j] = '.';
                bluePos = {i,j};
            }
        }
        getchar();
    }
    for(int i=1;i<m-1;i++){
        int up = 1;
        int low = n-2;
        for(int j=1;j<n-1;j++){
            ///up
            if(board[j][i] == '#'){
                up = j+1;
            }
            else if(board[j][i] == 'O'){
                up = j;
            }
            else{
                upBound[j][i] = up;
            }
            ///low
            if(board[n-1-j][i] == '#'){
                low = n-2-j;
            }
            else if(board[n-1-j][i] == 'O'){
                low = n-1-j;
            }
            else{
                lowBound[n-1-j][i] = low;
            }
            }
        }
    for(int i=1;i<n-1;i++){
        int left = 1;
        int right = m-2;
         ///left
         for(int j=1;j<m-1;j++){
              ///left
            if(board[i][j] == '#'){
                left = j+1;
            }
            else if(board[i][j] == 'O'){
                left = j;
            }
            else{
                leftBound[i][j] = left;
            }
            ///right
            if(board[i][m-1-j] == '#'){
                right = m-2-j;
            }
            else if(board[i][m-1-j] == 'O'){
                right = m-1-j;
            }
            else{
                rightBound[i][m-1-j] = right;
            }
         }
    }/*
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            cout<<rightBound[i][j]<<' ';
        }
        cout<<'\n';
    }*/

    int ret = findv(-1,-1,board,redPos,bluePos);
    cout<<(ret == 11 ? -1 : ret);
}