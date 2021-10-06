#include<bits/stdc++.h>
using namespace std;
int adj[8][8] = {   {0,1,1,0,0,0,0,0},
                    {1,0,1,1,0,0,0,0},
                    {1,1,0,1,1,0,0,0},
                    {0,1,1,0,1,1,0,0},
                    {0,0,1,1,0,1,1,0},
                    {0,0,0,1,1,0,0,1},
                    {0,0,0,0,1,0,0,1},
                    {0,0,0,0,0,1,1,0},
                };


void matrixMultiply(int mat1[][8], int mat2[][8], int ret[][8]){
    int mat11[8][8];
    int mat22[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            mat11[i][j] = mat1[i][j];
            mat22[i][j] = mat2[i][j];
            ret[i][j] = 0;
        }
    }
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                ret[i][j] += ((long long)mat11[i][k]*mat22[k][j])%1000000007;
                ret[i][j] %= 1000000007;
            }
        }
    }
}

void matrixPower(int mat[][8], int ret[][8], int n){
    if(n==1){
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                ret[i][j] = mat[i][j];
            }
        }
        return;
    }
    int here[8][8];
    matrixPower(mat, here, n/2);
    matrixMultiply(here,here,ret);
    if(n%2!=0){
        matrixMultiply(ret,mat,ret);
    }
}


int main(){
    int d;
    cin>>d;
    int ret[8][8] = {};
    matrixPower(adj, ret, d);
    cout<<ret[0][0];
}