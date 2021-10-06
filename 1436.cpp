#include<bits/stdc++.h>
using namespace std;
/*
    3자리 1 
    4자리 18
    5자리 3*
    6자리 
*/

bool countContinuousSix(int n){
    int ret = 0;
    while(n>0){
        if(n%10 == 6){
            if(++ret >= 3){
                return true;
            }
        }
        else
            ret = 0;
        n/=10;
    }
    return false;
}

int main(void){
    int a;
    cin >> a;
    int count=0;
    int i=0;
    while(count<a){
        i++;
        if(countContinuousSix(i)){
            count++;
        }
    }
    cout<<i;
}