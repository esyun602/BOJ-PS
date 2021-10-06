#include<bits/stdc++.h>
using namespace std;

//long long dp[10] = {};
long long num[10] = {};
/*
void findForTest(int n){
    for(int i=1;i<=n;i++){
        for(int digit=1;i/digit>0;digit*=10){
            dp[i/digit%10]++;
        }
    } 
}*/

void findByDigit(int digit, int n){
    if(n/digit==0)  return;
    for(int i=0;i<10;i++){
        num[i] += n/(digit*10) * digit;
    }
    if(n/digit/10>0){
        num[0]-=digit;
    }
    for(int i=0;i<n/digit%10;i++){
        if(n/(digit*10)==0 && i==0) continue;
        num[i] += digit;
    }
    num[n/digit%10] += n%digit+1;
    findByDigit(digit*10, n);
}


int main(){
    int n;
    cin>>n;
    findByDigit(1,n);
       // findForTest(n);
    if(num[0] == -1)
        num[0] = 0;
    for(int i=0;i<10;i++){
        cout<<num[i]<<' ';
    }
    /*cout<<'\n';
    for(int i=0;i<10;i++){
        cout<<dp[i]<<' ';
    }*/
}