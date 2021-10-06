#include<bits/stdc++.h>
using namespace std;


void multiplyMat(long long mat[][2], long long mat2[][2], long long ret[][2]){
    long long mat11[2][2];
    long long mat22[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            mat11[i][j] = mat[i][j];
            mat22[i][j] = mat2[i][j];
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ret[i][j] = 0;
            for(int k=0;k<2;k++){
                ret[i][j] += (mat11[i][k]%1000000007 * mat22[k][j]%1000000007)%1000000007;
            }
            ret[i][j] %= 1000000007;
        }
    }
}

void powMat(long long mat[][2], long long ret[][2], long long n){
    if(n==1){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ret[i][j] = mat[i][j];
            }
        }
        return;
    }
    long long here[2][2];
    powMat(mat, here, n/2);
    multiplyMat(here, here, ret);
    if(n%2 == 1){
        multiplyMat(ret, mat, ret);
    }
}


int main(){
    long long n;
    cin>>n;
    long long mat[2][2] = {{1,1},{1,0}};
    long long ret[2][2];
    powMat(mat, ret, n);
    cout<<ret[0][1];
    
}

//1000000000000000000 0 1 1 2 3 5 8 13 21
