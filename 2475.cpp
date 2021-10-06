#include<bits/stdc++.h>
using namespace std;
int main(){
    int ret=0;
    for(int i=0;i<5;i++){
        int a;
        cin>>a;
        ret += a*a;
    }
    cout<<ret%10;
}