#include<bits/stdc++.h>
using namespace std;
//value[n] <-- state[n-1], value[n-1]
int dp[100005][5][5];
int main(){
    int c=-1;
    int move[5][5] =    {{0,2,2,2,2},
                         {0,1,3,4,3},
                         {0,3,1,3,4},
                         {0,4,3,1,3},
                         {0,3,4,3,1}};
    vector<int> v(100005,2);
    int n=0;

    while(c!=0){
        cin>>c;
        n++;
        v[n] = c;
    }
    for(int i=0;i<=100000;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++)
                dp[i][j][k] = 0xfffffff;
        }
    }
    dp[0][0][0] = 0;
    dp[1][v[1]][0] = 2;
    dp[1][0][v[1]] = 2;
    for(int i=2;i<n;i++){
        int tmp = v[i];
        for(int j=0;j<5;j++){
            if(j==tmp)  continue;
            for(int k=0;k<5;k++){ 
                if(j==k)    continue;
                dp[i][j][tmp] = min(dp[i][j][tmp],dp[i-1][j][k] + move[k][tmp]);
                dp[i][tmp][j] = min(dp[i-1][k][j] + move[k][tmp],dp[i][tmp][j]);
            }
        }
    }
    int mini = 0xfffffff;
    for(int i=0;i<25;i++){
        mini = min(mini, dp[n-1][i/5][i%5]);
    }
    /*
   for(int i=0;i<n;i++){
    	for(int j=0;j<25;j++){
    		printf("dp[%d][%d][%d] = %d\n", i,j/5,j%5,dp[i][j/5][j%5]);
		}
		printf("==========\n");
	}
    */
    
    cout<<mini;



}
