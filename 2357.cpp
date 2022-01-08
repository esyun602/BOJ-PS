#include<iostream>
#include<algorithm>
using namespace std;

int numbers[100000];
int minSegTree[400000]; // val: minimum value of numbers in certain range
int maxSegTree[400000]; // val: maximum "
int fillMinSegVal(int left, int right, int now=0){
    if(left==right){
        return minSegTree[now] = numbers[left];
    }
    int mid = (left+right)/2;
    return minSegTree[now] = min(fillMinSegVal(left,mid,now*2+1), fillMinSegVal(mid+1,right,now*2+2));
}

int fillMaxSegVal(int left, int right, int now=0){
    if(left==right){
        return maxSegTree[now] = numbers[left];
    }
    int mid = (left+right)/2;
    return maxSegTree[now] = max(fillMaxSegVal(left,mid,now*2+1), fillMaxSegVal(mid+1,right,now*2+2));
}

void findValByRange(int a, int b, int left, int right, int now, int* minval, int* maxval){
    if(left==a && right==b){
        *minval = min(*minval, minSegTree[now]);
        *maxval = max(*maxval, maxSegTree[now]);
        return;
    }
    int mid = (left+right)/2;
    int ret;
    if(a>mid){
        findValByRange(a,b,mid+1,right,now*2+2, minval, maxval);
    }
    else if(b<=mid){
        findValByRange(a,b,left,mid,now*2+1, minval, maxval);
    }
    else{
        findValByRange(a,mid,left,mid,now*2+1, minval, maxval);
        findValByRange(mid+1,b,mid+1,right,now*2+2, minval, maxval);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    fillMinSegVal(0,n-1);
    fillMaxSegVal(0,n-1);
    for(int i=0;i<m;i++){
        int minval = 0x7fffffff;
        int maxval = -0x7fffffff;
        int a,b;
        cin>>a>>b;
        findValByRange(--a,--b,0,n-1,0,&minval,&maxval);
        cout<<minval<<' '<<maxval<<'\n';
    }
}