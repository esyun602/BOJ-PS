#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, pair<int, pair<int,int> > > p4;
typedef pair<int,int> pii;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end(), less<int>());
    long long mini = 0xfffffffffffff;
    int a[3];
    for(int k=0;k<n;k++){
        int i=k+1, j=n-1;
        while(i<n && j>i){
            long long val = (long long)v[i]+v[j]+v[k];
            if(abs(val)<mini){
                mini = abs(val);
                a[0] = v[i];
                a[1] = v[j];
                a[2] = v[k];
            }
            if(val>0){
                j--;
            }
            else if(val<0){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
    }
    sort(a, a+3);
    cout<<a[0]<<' '<<a[1]<<' '<<a[2];
  
}