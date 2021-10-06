#include<bits/stdc++.h>
using namespace std;
bool rowNum[9][10] = {};
bool colNum[9][10] = {};
bool squareNum[9][10] = {};
int board[9][9] = {};
bool dfs(int lev){
    if(lev == 81)   return true;
    int row = lev/9;
    int col = lev%9;
    if(board[row][col] !=0 ){
        return dfs(lev+1);
    }
    for(int i=1;i<=9;i++){
        if(!rowNum[row][i] && !colNum[col][i] && !squareNum[row/3*3+col/3][i]){
            rowNum[row][i] = colNum[col][i] = squareNum[row/3*3+col/3][i] = true;
            board[row][col] = i;
            if(dfs(lev+1))  return true;
            rowNum[row][i] = colNum[col][i] = squareNum[row/3*3+col/3][i] = false;
        }
    }
    board[row][col] = 0;
    return false;
}


int main(){
    for(int i=0;i<9;i++){
        int tmp;
        cin>>tmp;
        for(int j=8;j>=0;j--){
            board[i][j] = tmp%10;
            tmp/=10;
            if(board[i][j] !=0 ){
                rowNum[i][board[i][j]] = colNum[j][board[i][j]] = squareNum[i/3*3+j/3][board[i][j]] = true;
            }
        }
    }
    dfs(0);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}