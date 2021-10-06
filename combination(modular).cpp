#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;

long long modinv;

long long mpow(int n, int r){
    if(r==1){
        return n;
    }
    long long ret = mpow(n, r/2);
    if(r%2==1){
        ret  =  ((ret%MAX)*(ret%MAX))%MAX;
        ret = (ret*n)%MAX;
	}
    else ret =  ((ret%MAX)*(ret%MAX))%MAX;
    return ret;
}

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    long long a =1, b=1;
    for(int i=1;i<=n;i++){
    	a = (a*i)%MAX;
	}
	for(int i=1;i<=n-r;i++){
    	b = (b*i)%MAX;
	}
	for(int i=1;i<=r;i++){
    	b = (b*i)%MAX;
	}
    modinv = mpow(b, MAX-2);
    long long res = a*modinv;
    res%= MAX;
    
    printf("%lld", res);
}
