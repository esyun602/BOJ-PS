#include<bits/stdc++.h>
using namespace std;
int dp[2505];
char str[2505];
int n;
void findMaxPalindrom(int k, int* ii, int*jj){
    int i=0;
    while(k-i>=0 && k+i<n && str[k+i]==str[k-i]){
        i++;
    }
    int j=0;
    while(k-j>=0 && k+j+1<n && str[k+j+1]==str[k-j]){
        j++;
    }
    *ii = i;
    *jj = j;
}


int main(){
    int even;
    int odd;
    for(int i=0;i<2505;i++){
        dp[i] = 0xfffffff;
    }
    dp[0] = 1;
    cin >> str;
    n = strlen(str);
    for(int i=0;i<n;i++){
        findMaxPalindrom(i, &odd, &even);
        for(int j=0;j<odd;j++){
            dp[i+j] = min(i-j-1<0?1:dp[i-j-1]+1, dp[i+j]);
        }
        for(int j=0;j<even;j++){
            dp[i+j+1] = min(i-j-1<0 ?1: dp[i-j-1]+1, dp[i+j+1]);
        }
    }
    cout << dp[n-1];
    /*for(int i=0;i<n;i++){
        printf("%d ", dp[i]);
    }*/
}