#include <bits/stdc++.h>

bool isNumber(int n, int count){
    if(count == 3)
        return true;
    if(n==0)
        return false;
    
    if(n%10 == 6)
        count++;
    else count=0;
    return isNumber(n/10, count);
}

int main()
{
    int n;
    int count=0;
    int sample=0;
    scanf("%d", &n);
    while(count<n){
        if(isNumber(sample, 0)) 
            count++;
        sample++;  
    }
    printf("%d", sample-1);
}