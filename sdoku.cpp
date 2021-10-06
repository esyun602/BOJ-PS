#include<stdio.h>
int mul[9]= { 1000, 100, 10, 1, 100, 10, 1, 10, 1 };
int result[9][720][9];
int key;
void calcTriplesum(int board[][10], int lev, int m, int n)
{
	if(lev==10)
		return;
	int dodge=0;
	int k;
	int cop[9];
	for(int i=0;i<9;i++)
	{
		cop[i]=board[m][i+1];
	}	
	int num[10]={};
	int sum = board[m][0];
	for(int j=0;j<9;j++)
	{
		num[board[m][j+1]]++;
	}
	int dig=0;
	//
	if(board[m][1]==0)
	{
		board[m][1]=sum/mul[0]-n;
		if(num[board[m][1]]!=0)
			return;
		num[board[m][1]]++;
	}
	
	for(int i=1;i<10;i++)
	{
		
		if(num[i]!=0)
		{	
			dodge=1;
			continue;
		}
		dodge=0;
		if(board[m][lev]==0)
			board[m][lev]=i;
		else
		{
			lev++;
			i=0;
			continue;
		}
		calcTriplesum(board, lev+1, m, n);
		if(lev==9)
		{
			dig=0;
			for(int j=0;j<9;j++)
				dig += board[m][j+1]*mul[j];
			if(dig==sum)
			{
				for(k=0;k<720&&result[m][k][0]!=0;k++);
				for(int j=0;j<9;j++)
					result[m][k][j]=board[m][j+1];											
			}															
		}
		board[m][lev]=cop[lev-1];
	}
	if(dodge&&board[m][8]!=0)
	{
		dig=0;
			for(int j=0;j<9;j++)
				dig += board[m][j+1]*mul[j];
			if(dig==sum)
			{
				for(k=0;k<720&&result[m][k][0]!=0;k++);
				for(int j=0;j<9;j++)
					result[m][k][j]=board[m][j+1];											
			}															
	}
}
void copyBoard(int board1[][9], int row, int k)
{
	for(int i=0;i<9;i++)
		board1[row-1][i]=result[row-1][k][i];
}
void show(int board[][9])
{
	printf("\n");
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			printf("%d ", board[i][j]);
			printf("\n");
	}
	printf("\n");
}
int isSdoku_block(int board[][9], int row, int col, int lev)
{
	if(lev%3!=0)
		return 1;
	if(row>lev-1&&col==0)
	{
		return 1;
	}
	int num_block[10]={};
	int next_col = col==6 ? 0 : col+3;
	int next_row = next_col==0 ? row+3 : row;
	for(int j=0;j<3;j++)
		for(int k=0;k<3;k++)
		{
			if(num_block[board[row+j][col+k]]==0)
				 num_block[board[row+j][col+k]]++;
			else return 0;
		}
	return isSdoku_block(board, next_row, next_col, lev);
}

int isSdoku_line(int board[][9], int i, int lev)
{	
	int num_col[10]={};
	for(int k=0;k<lev;k++)
	{
		if(num_col[board[k][i]]==0)
			num_col[board[k][i]]++;
		else return 0;
	}
	if(i==8)
		return 1;
	return isSdoku_line(board, i+1, lev);
}

void makeSdoku(int board[][9], int lev)
{
	if(lev==10)
	{
		key=1;
		return;
	}
	int i=0;
	while(1)
	{
		copyBoard(board, lev, i);
		if(isSdoku_line(board, 0, lev)&&isSdoku_block(board, 0, 0, lev))
		{
			makeSdoku(board,lev+1);
			if(key)
				return;
		}
		i++;
		if(result[lev-1][i][0]==0)
		{
			copyBoard(board,lev,i);
			return;
		}
	}
}




int main()
{
	int board2[9][10]={};
	int board[9][10]={};
	int output[9][9]={};
	for(int i=0;i<9;i++)
	for(int j=0;j<10;j++)
	{
		scanf("%d", &board[i][j]);
		board2[i][j]=board[i][j];
	}
	for(int i=0;i<9;i++)
	{
		calcTriplesum(board,2, i, 1);
		
		
		if(board2[i][0]/mul[0]<10&&board2[i][1]==0)
			calcTriplesum(board2,2, i, 0);
	}
	makeSdoku(output, 1);
	show(output);
}
