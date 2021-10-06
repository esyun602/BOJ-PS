#include<stdio.h>
#include<stdlib.h>

int countRe(char model[][8], char board[][50], int startX, int startY){
    int num=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            if(model[i][j] != board[startY+i][startX+j])  num++;
    num = num>32 ? 64-num : num;
	return num;
}

int main(){
    char model[8][8];
    int tmp;
    int min = ~(1<<31);
    char s[2] = {'W', 'B'};
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            model[i][j] = s[(i+j)%2];
    char board[50][50] = {};
    int N;
    int M;
    scanf("%d %d", &N, &M);
    getchar();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++)
            scanf("%c", &board[i][j]);
        getchar();
		}
    for(int i=0;i<N-7;i++)
        for(int j=0;j<M-7;j++)
        {
            tmp = countRe(model, board, j, i);
            min = tmp> min ? min : tmp;
        }
    printf("%d", min);
    
}
