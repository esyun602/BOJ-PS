#include<bits/stdc++.h>
using namespace std;

int n;
int arr[20];
int plu;
int minu;
int cross;
int di;
int mini = ~(1<<31);
int maxi = (1<<31);
int tmp;

void find(int cur){
    if(cur==n){
        mini = min(mini, tmp);
        maxi = max(maxi, tmp);
        return;
    }
    int tmp2;
    if(plu!=0){
        plu--;
        tmp += arr[cur];
        find(cur+1);
        plu++;
        tmp -= arr[cur];
    }
    if(minu!=0){
        minu--;
        tmp -= arr[cur];
        find(cur+1);
        minu++;
        tmp += arr[cur];
    }
    if(cross!=0){
        cross--;
        tmp *= arr[cur];
        find(cur+1);
        cross++;
        tmp /= arr[cur];
    }
    if(di!=0){
    	di--;
    	tmp2 = tmp;
    	tmp /= arr[cur];
    	find(cur+1);
    	di++;
    	tmp = tmp2;
	}
}

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    tmp = arr[0];
    scanf("%d %d %d %d", &plu, &minu, &cross, &di);
    find(1);
    printf("%d\n", maxi);
    printf("%d\n", mini);
}
