#include<bits/stdc++.h>
using namespace std;

int mpow(long long a,long long b, long long c){
    if(b==1)
        return a%c;
    long long ret;
    
    ret = mpow(a,b/2,c);
    ret = (ret*ret)%c;
    if(b%2==1){
        ret = (ret*a)%c;    
    }
    return ret%c;
}

int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    printf("%d", mpow(a,b,c));
}