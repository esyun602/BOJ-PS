#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    cin>>n>>s;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int minlen = 0xfffffff;
    vector<int> sum(n+1); // [)
    sum[0] = 0;
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i]+v[i];
    }
    int left=0,right=0;
    while(right<n+1){
        int val = sum[right] - sum[left]; // [left, right)
        if(val<s){
            right++;
        }
        else if(val>s){
            minlen = min(minlen, right-left);
            left++;
        }
        else{
            minlen = min(minlen, right-left);
            left++;
            right++;
        }
    }
    if(minlen == 0xfffffff)
        minlen = 0;
    cout<<minlen;
}