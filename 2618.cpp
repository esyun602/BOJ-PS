#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef pair<int,int> pii;

int manhattanDistance(pii &x, pii &y){
    return abs(x.first-y.first) + abs(x.second-y.second);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int dp[1001] = {};
    int link[1001] = {};
    pii point[1001] = {};
    int n;
    int w;
    cin>>n>>w;
    pii incident[1000];
    for(int i=0;i<w;i++){
        int x,y;
        cin>>x>>y;
        incident[i] = {x,y};
    }
    point[0] = {n,n};
    point[1] = {1,1};
    dp[0] = manhattanDistance(incident[0], point[1]);
    dp[1] = manhattanDistance(incident[0], point[0]);
    for(int i=1;i<w;i++){/*
    for(int j=0;j<=w;j++){
        printf("%d ", dp[j]);
    }
    printf("\n");*/
    
        int mini = 0xfffffff;
        int minindex;
        for(int j=0;j<i+1;j++){
            if(mini>dp[j]+manhattanDistance(point[j],incident[i])){
                mini = dp[j] + manhattanDistance(point[j],incident[i]);
                minindex = j;
            }
            dp[j] = dp[j] + manhattanDistance(incident[i-1], incident[i]);
        }
        link[i+1] = minindex;
        dp[i+1] = mini;
        point[i+1] = incident[i-1];

    }
    int mini = 0xfffffff;
    int minIndex=-1;
    for(int i=0;i<w+1;i++){
        if(mini>dp[i]){
            mini = dp[i];
            minIndex = i;
        }
    }
    cout<<mini<<'\n';
    stack<bool> s;
    for(int i=w;i>=0;i--){
        if(minIndex == i){
            s.push(false);
            if(i<=1)
                break;
            else
                minIndex = link[minIndex];
        }
        else{
            if(i==1){
                s.push(false);
                break;
            }
            s.push(true);
        }
    }
    s.pop();
    int val = (int)(minIndex == 1);
    cout<<val+1<<"\n";
    while(!s.empty()){
        int tmp = s.top();
        s.pop();
        if(tmp){
            cout<<val+1<<"\n";
        }
        else{
            val = (val+1)%2;
            cout<<val+1<<'\n';
        }
    }
}