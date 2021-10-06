#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    pair<long long,pair<long,long> > mini = {0xffffffffffffff, {0,0}};
    cin>>n;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int i=0,j=n-1;
    while(j>i){
        long long val = v[j]+v[i];
        if(mini.first > abs(val)){
            mini = {abs(val),{v[i],v[j]}};
        }
        if(val>0){
            j--;
        }
        else if(val<0){
            i++;
        }
        else{
            break;
        }
    }
    cout<<mini.second.first<<" "<<mini.second.second;
}