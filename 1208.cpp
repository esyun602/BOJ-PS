#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long s;
    long long sum;
    cin >> n >> s;
    int mid = n/2;
    long long ans=0;
    int cnt=0;
    vector<int> v(n);
    map<int, int> m;  
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    for(int i=0;i< (1 << mid);i++){
        sum=0;
        for(int j=0; j<mid;j++){
            if(i&(1<<j)){
                sum+=v[j];
            }
        }
        m[sum]++;
    }

    
    for(int i=0;i<(1<<n-mid);i++){
        sum=0;
        for(int j=0; j<n-mid;j++){
            if(i&(1<<j))
                sum+=v[j+mid];
        }
        ans += m[s-sum];  
    }
    
    if(s==0)    ans--;
    printf("%lld", ans);
}
