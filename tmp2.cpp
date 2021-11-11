#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    srand(time(NULL));
    a = rand()%10000 + 1;
    b = rand()%(a) + a;
    cout<< a<<' '<<b<<'\n';
    for(int i=0;i<b;i++){
        cout<<rand()%(a) + 1<<' '<<rand()%(a) + 1<<'\n';
    }
}