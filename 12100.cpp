#include<bits/stdc++.h>
using namespace std;
#define LEFT    0
#define UP      1
#define RIGHT   2
#define DOWN    3
int n;


int findMax(int count, int dir, vector<vector<int>>board){
	bool block = false;
    int ret=0;
    int cnt=0;
    switch (dir)
    {
        case LEFT:
            for(int i=0;i<n;i++){
            	block = false;
            	cnt=0;
                for(int j=0;j<n;j++){
                    if(board[i][j]==0)  continue;
                    if(!block && cnt!=0 && board[i][cnt-1] == board[i][j]){
                    	block = true;
                        board[i][cnt-1]*=2;
                        board[i][j] = 0;
                    }
                    else{
                    	block = false;
                        board[i][cnt] = board[i][j];
                        if(j!=cnt)
                            board[i][j] = 0;
                        cnt++;
                    }
                }
            }
            break;
        case UP:
            for(int i=0;i<n;i++){
            	block = false;
            	cnt=0;
                for(int j=0;j<n;j++){
                    if(board[j][i]==0)  continue;
                    if(!block && cnt!=0 && board[cnt-1][i] == board[j][i]){
                    	block = true;
                        board[cnt-1][i]*=2;
                        board[j][i] = 0;
                    }
                    else{
                    	block = false;
                        board[cnt][i] = board[j][i];
                        if(j!=cnt)
                            board[j][i] = 0;
                        cnt++;
                    }
                }
            }
        break;
        case RIGHT:
            for(int i=0;i<n;i++){
            	block = false;
            	cnt=0;
                for(int j=n-1;j>=0;j--){
                    if(board[i][j]==0)  continue;
                    if(!block && cnt!=0 && board[i][n-cnt] == board[i][j]){
                    	block = true;
                        board[i][n-cnt] *= 2;
                        board[i][j] = 0;
                    }
                    else{
                    	block = false;
                        board[i][n-cnt-1] = board[i][j];
                        if(j!=n-cnt-1)
                            board[i][j] = 0;
                        cnt++;
                    }
                }
            }
            break;
        case DOWN:
            for(int i=0;i<n;i++){
            	block = false;
            	cnt=0;
                for(int j=n-1;j>=0;j--){
                    if(board[j][i]==0)  continue;
                    if(!block && cnt!=0 && board[n-cnt][i] == board[j][i]){
                    	block = true;
                        board[n-cnt][i]*=2;
                        board[j][i] = 0;
                    }
                    else{
                    	block = false;
                        board[n-1-cnt][i] = board[j][i];
                        if(j!=n-1-cnt)
                            board[j][i] = 0;
                        cnt++;
                    }
                }
            }
            break;
        default:
            break;
    }
    /*for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<board[i][j]<<' ';
		}
		cout<<endl;
	}
	cout<<endl;*/
    count++;
    if(count == 5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ret = max(ret, board[i][j]);
            }
        }
        return ret;
    }
    ret = max(ret,findMax(count, LEFT,board));
    ret = max(ret,findMax(count, UP,board));
    ret = max(ret,findMax(count, RIGHT,board));
    ret = max(ret,findMax(count, DOWN,board));
    return ret;
}

int main(){
	vector<vector<int>> board(20, vector<int>(20,0));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    cout<<findMax(-1,-1, board);

}
