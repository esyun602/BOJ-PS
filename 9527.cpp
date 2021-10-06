#include<bits/stdc++.h>
using namespace std;

long long dpComb[70][70];
//실수 
//long long 비트마스킹: LL접미사 활용 
// 
long long calcComb(int a,int b){
    if(dpComb[a][b]!=0){
        return dpComb[a][b];
    }
    return dpComb[a][b] = calcComb(a-1,b-1) + calcComb(a-1,b);
    
}


int calcDigit(long long n){
    int cnt = 0;
    while(n){
        cnt++;
        n/=2;
    }
    return cnt;
}

long long calcCaseBasedDigit(int digit, long long n){
    long long ret =0;
    int cnt = -1;
    for(int i=(digit-1); i>=0;i--){
        
        if(n&(1LL<<i)){
            cnt++;
            for(int j=0;j<=i;j++){
                ret += (j+cnt)*calcComb(i,j);
            }
            ret++;
        }
    }
    return ret;
}

int main(){
    long long a,b;
    cin>>a>>b;
    for(int i=1;i<70;i++){
        dpComb[i][0] = dpComb[i][i] = 1;
    }
    dpComb[0][0] = 1;
    b = calcCaseBasedDigit(calcDigit(b), b);
    a = calcCaseBasedDigit(calcDigit(a-1), a-1);
    cout<<b-a;
}
