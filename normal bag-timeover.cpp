#include<bits/stdc++.h>
using namespace std;
pair<int, int> arr[100];
int weight;
int value;
int maxi = (1<<31);
int n;
int k;
int dp[100];

void dfs(int cur){
    maxi = max(maxi, value);
    for(int i=cur;i<n;i++){
        if(weight+arr[i].first<=k){
            weight+=arr[i].first;
            value += arr[i].second;
            dfs(1+i);
            weight-=arr[i].first;
            value -= arr[i].second;
        }
    }
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++)
        scanf("%d %d", &arr[i].first, &arr[i].second);
    dfs(0);
    printf("%d", maxi);
}
