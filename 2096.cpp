#include<iostream>
#include<algorithm>
using namespace std;
int dp[3];
int dpmin[3];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        int a1,b1,c1;
        cin>>a>>b>>c;
        a1 = a + max(dp[0],dp[1]);
        b1 = b + max(max(dp[0], dp[1]), dp[2]);
        c1 = c + max(dp[1], dp[2]);
        dp[0] = a1;
        dp[1] = b1;
        dp[2] = c1;
        a1 = a + min(dpmin[0],dpmin[1]);
        b1 = b + min(min(dpmin[0], dpmin[1]), dpmin[2]);
        c1 = c + min(dpmin[1], dpmin[2]);
        dpmin[0] = a1;
        dpmin[1] = b1;
        dpmin[2] = c1;
    }
    cout<<max(max(dp[0], dp[1]), dp[2]) <<' '<<min(min(dpmin[0], dpmin[1]), dpmin[2]);
}