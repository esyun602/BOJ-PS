#include<bits/stdc++.h>
using namespace std;
int dp[100000];

int main(){
    int w[100], v[100];
    int n;
    int k;
    scanf("%d", &n);
    scanf("%d", &k);
    for(int i=0;i<n;i++)
        scanf("%d %d", &w[i], &v[i]);
    for(int i=0;i<n;i++){
        for(int j=k;j>0;j--){
            if(j<w[i])
                continue;
            dp[j] = max(dp[j] ,dp[j-w[i]]+v[i]);
        }
    }
    printf("%d", dp[k]);
}
