#include<iostream>
#include<vector>
using namespace std;

int card[4000001]={};
int used[4000001] = {};

int drawCard(int cardNum){
    int toDraw = card[cardNum];
    if(used[toDraw]){
        int ret = drawCard(toDraw);
        card[cardNum] = card[ret];
        return ret;
    }
    return toDraw;
}

int main(){
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        card[a] = 1;
    }
    int rightCard = -1;
    for(int i=4000000;i>=0;i--){
        if(card[i]){
            card[i] = rightCard;
            rightCard = i;
        }
        else{
            card[i] = rightCard;
        }
    }
    for(int i=0;i<k;i++){
        int tmp;
        cin>>tmp;
        int c = drawCard(tmp);
        used[c] = 1;
        cout<<c<<'\n';
    }
}