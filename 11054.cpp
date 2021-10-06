#include<bits/stdc++.h>

int maxi = -1;
int arr[1000];
int dpinc[1000] = {1};
int dpdec[1000] = {1};
int main(){
	printf("%d", dpinc[2]);
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]>=arr[i])
                continue;
            if(dpinc[j]+1>maxi){
                maxi = dp[j];
            }
        } 
        dpinc[i] = maxi;
        maxi = -1
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[j]>=arr[i])
                continue;
            if(dpdec[j]+1>maxi){
                maxi = dp[j];
            }
        } 
        dpdec[i] = maxi;
        maxi = -1
    }
    for(int i=0;i<n;i++){
        maxi = max(dpinc[i]+dpdec[i]-1, maxi);
    }
    printf("%d", maxi);
    
}
