#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> l;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n;i++){
        if(l.empty() || l[l.size()-1] < v[i]){
            l.push_back(v[i]);
        }
        else{
            *lower_bound(l.begin(), l.end(), v[i]) = v[i];
        }
    }
    cout<<l.size();
}