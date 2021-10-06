#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<long long> v(n+1);
    vector<int> index;
    vector<bool> pushed(n+1);
    vector<long long> data(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    vector<long long> sum(n+1);
    for(int i=1;i<=n;i++){
        sum[i] = sum[i-1]+v[i];
    }
    for(int i=0;i<m+k;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        if(a==1){
            if(!pushed[b]){
                pushed[b] = true;
                index.push_back(b);
            }
            data[b] = c;
         }
        else{
            long long ret = sum[c] - sum[b-1];
            for(int j=0;j<index.size();j++){
                if(index[j]>= b && index[j] <=c){
                    ret = ret - v[index[j]] + data[index[j]];
                }
            }
            cout<<ret<<'\n';
        }
    }
}