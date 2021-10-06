#include<bits/stdc++.h>
using namespace std;
bool board[8][8];
int qloc[8];
int origin[8];

///배열 row column 구분
///각 루프 상단 값 초기 화 

int find_by_col(int i){
    int ret = 0;
    int dx, dy;
    dx = dy = 1;
    while(i + dx < 8){
        if(board[qloc[i]][i+dx]){
            ret++;
            break;
        }
        dx++;
    }
    dx = dy = 1;
    while(qloc[i]+dx<8 && i + dy<8){
        if(board[qloc[i]+dx][i+dy]){
            ret++;
        break;
        }
        dx++;
        dy++;
                    }
                    dx = dy = 1;
                    while(qloc[i]-dx>=0 && i+dy<8){
                        if(board[qloc[i]-dx][i+dy]){
                            ret++;
                            break;
                        }
                        dx++;
                        dy++;
                    }
    return ret;
}
void print_board();
int find_all(){
    int x=0;
    for(int i=0;i<8;i++){
        x+=find_by_col(i);
    }
    return x;
}
void print_board(){
	printf("================\n");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]) printf("O ");
            else printf("X ");
        }
        printf("\n");
    }
    printf("================\n");

}


void hill_climbing(){
    
    int cas = 0;
    while(1){
		int x=-1;
        cas++;
        for(int i=0;i<8;i++){
        	for(int j=0;j<8;j++){
        		board[i][j] = 0;
			}
		}
        for(int i=0;i<8;i++){
            int num = rand() % 8;
            board[num][i] = 1;
            qloc[i] = num;
        }
        while(1){
            if(x==-1){
                x=0;
                int dx, dy;
                x= find_all();
            }
            if(x==0){
                print_board();
                printf("cas: %d", cas);
                return;
            }    
            int mini = x;
            int col;
            int row;
            for(int i=0;i<8;i++){
                int origin = qloc[i];
                for(int j=0;j<8;j++){
                    qloc[i] = j;
                    int tmp = find_all();
                    if(tmp<mini){
                        mini = tmp;
                        col = i;
                        row = j;
                    }
                }
                qloc[i] = origin;
            }
            if(mini<x){
            	x = mini;
            	
            	print_board();
                board[qloc[col]][col] = 0;
                qloc[col] = row;
                board[row][col] = 1;
				printf("x: %d\n", mini);
            }
            else break;
        }
    }
}



int main(){
    srand(time(NULL));
    hill_climbing();
}
