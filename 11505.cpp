#include<iostream>
using namespace std;
int n;
long long segTree[4000000];
int num[1000001];
long long createSeg(int left=1, int right = n, int now=0){
    int mid = (left+right)/2;
    if(left==right){
        return segTree[now] = num[left];
    }

    return segTree[now] = (createSeg(left,mid,now*2+1) * createSeg(mid+1,right,now*2+2))%1000000007;

}
void changeSeg(int toFind, int val, int left= 1, int right = n, int now = 0){
    int mid = (left+right)/2;
    if(left==right){
        segTree[now] = val;
        return;
    }
    if(toFind>mid){
        changeSeg(toFind,val,mid+1,right,now*2+2);
        segTree[now] = (segTree[now*2+1]*segTree[now*2+2])%1000000007;
    }
    else{
        changeSeg(toFind,val,left,mid,now*2+1);
        segTree[now] = (segTree[now*2+1]*segTree[now*2+2])%1000000007;
    }
}

long long findRange(int leftToFind, int rightToFind, int left=1, int right=n, int now=0){
    int mid = (left+right)/2;
    if(left==leftToFind && rightToFind == right)
        return segTree[now];
    if(rightToFind<=mid){
        return findRange(leftToFind,rightToFind,left,mid,now*2+1);
    }
    else if(leftToFind>mid){
        return findRange(leftToFind, rightToFind, mid+1, right, now*2+2);
    }
    else{
        return (findRange(leftToFind, mid, left, mid, now*2+1) * findRange(mid+1, rightToFind, mid+1, right,now*2+2)) % 1000000007;
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    createSeg();
    for(int i=0;i<m+k;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            changeSeg(b,c);
            num[b] = c;
        }
        else{
            cout<<findRange(b,c)<<'\n';
        }
    }
}