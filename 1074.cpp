#include<bits/stdc++.h>

int main(){
    int n, r, c;
    scanf("%d %d %d", &n, &r, &c);
    int ret=0;
    int startr=0, startc =0;
    int endr = pow(2,n), endc = pow(2,n);
    int data =pow(4,n)/4;
    while(startr != r || startc != c){
        int midr = (startr+endr)/2;
        int midc = (startc+endc)/2;
        if(r>=midr){
            ret += 2*data;
            startr = midr;
        }
        else endr = midr;
        
        if(c>=midc){
            ret+= data;
            startc = midc;
        }
        else endc = midc;
        data/=4;
    }
    printf("%d", ret);
}
