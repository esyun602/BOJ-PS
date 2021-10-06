#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    int cnt=0;
    vector<int> v(n+5,1);
    vector<int> pr;
    for(int i=2;i<=n;i++){
        if(v[i]==1){
            pr.push_back(i);
            for(int j=1;i*j<=n;j++){
                v[i*j]=0;
            }
        }
    }
    vector<int> sum(pr.size()+5);
    if(n==1){
        cout<<0;
        return 0;
    }
    sum[0] = pr[0];
    for(int i=1;i<pr.size();i++){
        sum[i] = sum[i-1]+pr[i];
    }
    int left=0;
    int right=0;
    while(right<pr.size()){
        int data = sum[right]-(left-1==-1 ? 0 : sum[left-1]);
        if(data==n){
            cnt++;
            right++;
            left++;
        }
        else if(data<n){
            right++;
        }
        else{
            left++;
        }
    }
    cout<<cnt;
}