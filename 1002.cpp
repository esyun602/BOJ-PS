#include<bits/stdc++.h>
using namespace std;

int dist(int x1,int y1,int x2, int y2){
    return (pow(x1-x2,2)+pow(y1-y2,2));
}

int main(){
    int tc;
    cin>>tc;
    while(tc-->0){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        if(x1==x2 && y1==y2 && r1==r2){
            cout<<-1<<'\n';
            continue;
        }
        int distance = dist(x1,y1,x2,y2);
        if(distance == pow(r1+r2,2)){
            cout<<1<<'\n';
        }
        else if(distance>pow(r1+r2,2)){
            cout<<0<<'\n';
        }
        else if(distance<pow(max(r1,r2),2)){
            if(distance == pow(r1-r2,2)){
                cout<<1<<'\n';
            }
            else if(distance<pow(r1-r2,2)){
                cout<<0<<'\n';
            }
            else{
                cout<<2<<'\n';
            }
        }
        else{
            cout<<2<<'\n';
        }
    }
}
