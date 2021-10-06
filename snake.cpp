#include<bits/stdc++.h>
using namespace std;

void showboard(int board[][120], int n){
	for(int i=0;i<n+2;i++){
		for(int j=0;j<n+2;j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(){
    pair<int, char> arr[100];
    int move2[2] = {0,1};
    int rotatei[4] = {0, -1, 0, 1};
    int rotatej[4] = {1, 0, -1, 0};
    int r = 0;
    int r2 = 0;
    int t=0;
    int move[2] = {0, 1};
    int board[120][120] = {};
    int headi, headj;
    int tail[2] = {1, 1};
    int applei, applej;
    int n;
    int k;
    int l;
    int x;
    int time=0;
    int count=0;
    int c2 = 0;
    char c; // L: left D: right
    scanf("%d %d", &n, &k);
    for(int j=0;j<n+2;j++){
        board[0][j] = 1;
        board[n+1][j] = 1;
        board[j][0] = 1;
        board[j][n+1] = 1;
    }
    headi = headj = 1;
    board[headi][headj] = 1;
    for(int i=0;i<k;i++){
        scanf("%d %d", &applei, &applej);
        board[applei][applej] = 2;
    }
    scanf("%d", &l);
    for(int i=0;i<l;i++){
        scanf("%d %c", &x, &c);
        arr[i].first = x;
        arr[i].second = c;
    }
    while(1){
    	time++;
        headi += move[0];
        headj += move[1];
        if(board[headi][headj] == 1){
            printf("%d", time);
            return 0;
        }
        
        
        if(board[headi][headj]!=2){
        	
        	board[tail[0]][tail[1]] = 0;
        	
        	if(t == arr[c2].first){
            switch(arr[c2].second){
                case 'L':
                    ++r2 %= 4;
                    break;
                case 'D':
                    --r2 += 4;
                    r2%=4;
                    break;                
            }
            move2[0] = rotatei[r2];
            move2[1] = rotatej[r2];
            c2++;
        }
        tail[0] += move2[0];
        tail[1] += move2 [1];
        
        	t++;
		}
		
		
        board[headi][headj] = 1;
        if(time == arr[count].first){
            switch(arr[count].second){
                case 'L':
                    ++r %= 4;
                    break;
                case 'D':
                    --r += 4;
                    r%=4;
                    break;                
            }
            move[0] = rotatei[r];
            move[1] = rotatej[r];
            count++;
        }
    }
}
