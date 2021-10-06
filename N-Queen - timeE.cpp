#include<bits/stdc++.h>
#define seg curi+i>-1 && curi+i<n && curj+i>-1 && curj+i<n
#define seg2 curi+i>-1 && curi+i<n &&curj-i>-1 && curj-i<n
int n;
int cnt;
int num=1;
int board[15][15]; // -1: ㅂㄱㄴ 0: ㄱㄴ 1: 이미o
void showboard(){
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%2d", board[i][j]);
		}
		printf("\n");
	}
}
void queen(int curi, int curj){
	if(n == 1){
		cnt =1;
		return;
	}
	

	if(num==n){
		cnt++;
		return;
	}
	
   	board[curi][curj] = 1;
    
    for(int i=0;i<n;i++)
        if(i!=curi)
            board[i][curj] -= 1;
    for(int j=0;j<n;j++)
        if(j!=curj)
            board[curi][j] -= 1;
    for(int i=-n+1;i<n;i++){
    	if(seg && i!=0)
    		board[curi+i][curj+i] -= 1;
	}	
	for(int i=-n+1;i<n;i++){
		if(seg2 && i!=0)
		board[curi+i][curj-i] -=1;

	}
    for(int i=curi+1;i<n;i++)
        for(int j=0;j<n;j++){
            if(board[i][j] == 0){
                num++;
                queen(i,j);
        		num--;
        		
            }
        }
        
    for(int i=0;i<n;i++)
        if(i!=curi)
            board[i][curj] +=1;
    for(int j=0;j<n;j++)
            board[curi][j] +=1;
    for(int i=-n+1;i<n;i++){
    	if(seg && i!=0)
    		board[curi+i][curj+i] +=1;
    	
	}
	for(int i=-n+1;i<n;i++){
		if(seg2&&i!=0)
		board[curi+i][curj-i] +=1;
	}   
	board[curi][curj] = 0;
}

int main(){
    scanf("%d", &n);
        for(int j=0;j<n;j++)
            queen(0, j);
    printf("%d", cnt);

}
