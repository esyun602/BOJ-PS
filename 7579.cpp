#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

/*
    top down방식의 dp 공부하기
    반드시 테이블에 정확한 상태가 모두 기술되어 있어야함
    순서 강제할 수 없음

    dp에서 변수 변경
    dp: state에 대한 제약, 
    
    amount에 대한 제약==>       자원 x를 최대(최소) a만큼 사용해서 자원 y의 최대(최소)를 만든다.
                                <===> 모든 y에 대해  최대(최소) x dp테이블을 완성 ==> y값을 키워(줄여)나가며 제약을 성립시키는지 확인(greedy)
    
*/


int dp[10001]; 
int n,m;
vector<int> mem(100);
vector<int> cost(100);

int main(){
    cin>>n>>m;
    for(int i=0;i<=10000;i++){
        dp[i] = -0xfffffff;
    }
    dp[0] = 0;
    for(int i=0;i<n;i++){
        cin>>mem[i];
    }
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    for(int j=0;j<n;j++){
        for(int i=10000;i>=0;i--){
            if(i-cost[j]<0) break;
            dp[i] = max(dp[i], dp[i-cost[j]] + mem[j]);
        }
    }
    for(int i=0;i<=10000;i++){
        if(dp[i]>=m){
            cout<<i;
            return 0;
        }
    }
    
}