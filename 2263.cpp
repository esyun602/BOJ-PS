#include<bits/stdc++.h>
using namespace std;
//실수
//서로 다른 배열 index간의 호환 문제
//배열 space를 맞추거나 거리 개념으로 접근
int n;
int inord[100001];
int postord[100000];
void fillTree(int start, int end, int diff){//[start,end)

    if(start>=end)
        return;
    int next;
    
    int root = postord[end-1];
    int inordIndex = inord[root];
    next = inordIndex - diff;
    cout<<root<<' ';
    fillTree(start, next,  diff);
    fillTree(next, end-1, diff+1);
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        inord[a] = i;
    }
    for(int i=0;i<n;i++){
        cin>>postord[i];
    }
    fillTree(0,n,0);
}
