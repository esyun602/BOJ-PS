#include<bits/stdc++.h>

int main(){
    int cnt=0;
    int n;
    int k;
    int arr[10];
    scanf("%d %d", &n, &k);
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    for(int i=n-1;i>=0;i--){
        while(k>=arr[i]){
            k-=arr[i];
            cnt++;
        }
    }
    printf("%d", cnt);
}
