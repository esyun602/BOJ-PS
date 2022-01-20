#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
int segTree[800000];
int index[100001];
int n,m;
int createSeg(int left=1, int right=n+m, int now=0){
    int mid = (left+right)/2;
    if(left==right){
        segTree[now] = left>n ? 0 : 1;
        return segTree[now];
    }
    return segTree[now] = createSeg(left,mid,now*2+1) + createSeg(mid+1,right,now*2+2);
}

int findRange(int leftToFind, int rightToFind, int left=1, int right=n+m, int now=0){
    if(rightToFind<leftToFind)  return 0;
    int mid = (left+right)/2;
    if(left == leftToFind && right == rightToFind){
        return segTree[now];
    }
    if(rightToFind<=mid){
        return findRange(leftToFind,rightToFind,left,mid,now*2+1);
    }
    else if(leftToFind>mid){
        return findRange(leftToFind,rightToFind,mid+1,right,now*2+2);
    }
    else{
        return findRange(leftToFind,mid,left,mid,now*2+1) + findRange(mid+1,rightToFind,mid+1,right,now*2+2);
    }
}

void addVal(int num, int val, int left=1, int right=n+m, int now=0){
    int mid = (left+right)/2;
    segTree[now]+=val;
    if(right==left) return;
    if(num<=mid){
        addVal(num,val,left,mid,now*2+1);
    }
    else{
        addVal(num,val,mid+1,right,now*2+2);
    }
}

void drawDVD(int cnt, int dvdNum){
    addVal(dvdNum, -1);
    addVal(cnt+n, 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin>>tc;
    while(tc--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            index[i] = n+1-i;
        }
        createSeg();
        for(int i=0;i<m;i++){
            int tmp;
            cin>>tmp;
            cout<<findRange(index[tmp]+1,n+i+1)<<' ';
            drawDVD(i+1,index[tmp]);
            index[tmp] = i+1+n;
        }
        cout<<'\n';
    }
}