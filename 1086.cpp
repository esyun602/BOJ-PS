#include<bits/stdc++.h>
using namespace std;


//실수목록
//자료형
//dp를 할때 index로 현재 상태를 완벽히 추정할 수 있는 값을 넣어야됨
//비용이 큰 계산은 미리
//
//
int n;
long long dp[100][1<<15];
int arrmod[100][15];
vector<string> v;
int k;

long long fact(int n){
    if(n==0)    return 1;
    return fact(n-1)*n;
}

int arrMod(string a, int d){
   int len =  a.length();
   int tmp=0;
   for(int i=0;i<len;i++){
       tmp *= 10;
       tmp = (tmp + a[i]-'0')%d;
   }
   return (tmp);
}

long long dfs(int cur, int r, int vis){
    vis |= 1<<cur;
    int r2 = arrmod[r][cur];
    if(dp[r2][vis]!=-1)    return dp[r2][vis];
    if(vis == (1<<n)-1 && r2!=0) return dp[r2][vis] = 0;
    else if(vis==(1<<n)-1) return dp[r2][vis] = 1;

    long long ret=0;
    for(int i=0;i<n;i++){
        if(vis & 1<<i)  continue;
        ret += dfs(i, r2, vis);
    }
    return dp[r2][vis] = ret;
}

long long gcd(long long a, long long b){
    if(b==0)    return a;
    return gcd(b,a%b);
}

int main(){
    memset(dp,-1,sizeof(dp));
    long long q = 0;
    long long p=0;
    cin>>n;
    q = fact(n);
    for(int i=0;i<n;i++){
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cin>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            arrmod[j][i] = arrMod(to_string(j)+v[i],k);
        }
    }

    for(int i=0;i<n;i++){
        p += dfs(i,0,0);
    }
    long long g = gcd(q,p);
    p /= g;
    q /= g;
    cout<<p<<'/'<<q;
}