#include<iostream>
using namespace std;
long long tree[4000000];

void segInsert(int n, int amount, int left=1, int right=1000000, int now=0){
    tree[now]+=amount;
    if(left==right) return;
    int mid = (left+right)/2;
    if(n<=mid){
        segInsert(n,amount,left,mid,now*2+1);
    }
    else{
        segInsert(n,amount,mid+1,right,now*2+2);
    }
}
int segFind(int n, int left=1, int right=1000000, int now=0){
   //printf("n:%d, left:%d, right:%d, val:%d\n", n,left,right,tree[now]);
    tree[now]--;
    if(left==right){
        return left;
    }
    int mid = (left+right)/2;
    if(tree[now*2+1]>=n){
        return segFind(n,left,mid,now*2+1);
    }
    else{
        return segFind(n-tree[now*2+1], mid+1, right, now*2+2);
    }
}

int main(){
    /*ios::sync_with_stdio(false);
    cin.tie(0);*/
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a;
        switch(a){
            case 1:
                cin>>b;
                cout<<segFind(b)<<'\n';
                break;
            case 2:
                cin>>b>>c;
                segInsert(b,c);
                                  
        }
    }
}