#include<bits/stdc++.h>
using namespace std;

void swtichOn(bool board[][10], int nowI, int nowJ){
    board[nowI][nowJ] ^= true;
    if(nowI!=0){
        board[nowI-1][nowJ] ^= true;
    }
    if(nowJ!=0){
        board[nowI][nowJ-1] ^= true;
    }
    if(nowI !=9){
        board[nowI+1][nowJ] ^= true;
    }
    if(nowJ!=9){
        board[nowI][nowJ+1] ^= true;
    }
}

int switching(bool board[][10], int lev){//cout<<lev<<'\n';
    int ret = 0xfffffff;
    if(lev/10 == 0){
        swtichOn(board, lev/10, lev%10);
        ret = min(ret, switching(board, lev+1)+1);
        swtichOn(board, lev/10, lev%10);
        ret = min(ret, switching(board, lev+1));
        return ret;
    }
    else{
        if(lev == 100){
            for(int i=0;i<10;i++){
                if(board[lev/10 - 1][i])
                    return 0xfffffff;
            }
            return 0;
        }
        if(board[lev/10 - 1][lev%10]){
            swtichOn(board, lev/10, lev%10);
            ret = switching(board,lev+1)+1;
            swtichOn(board, lev/10, lev%10);
            return ret;
        }
        else return switching(board, lev+1);
    }
    
}

int main(){
    bool board[10][10] = {};
    for(int i=0;i<10;i++){
        string s;
        cin>>s;
        for(int j=0;j<10;j++){
            if(s[j]=='O')
                board[i][j] = true;
        }
    }
    int out = switching(board,0);
    if(out>100){
        cout<<-1;
    }
    else cout<<out;
    
}