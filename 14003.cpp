#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> l;
    vector<int> v(n);
    vector<int> lev(n);
    int last = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(l.empty() || l[l.size()-1] < v[i]){
            l.push_back(v[i]);
            lev[i] = l.size()-1;
            last = i;
        }
        else{
            int lb = lower_bound(l.begin(), l.end(), v[i]) - l.begin();
            l[lb] = v[i];
            lev[i] = lb;
        }
    }
    cout<<l.size()<<'\n';
    int count = l.size()-1;
    l.clear();
    while(count>=0){
        if(lev[last] == count){
            count--;
            l.push_back(v[last]);
        }
        last--;
    }
    for(int i=l.size()-1;i>=0;i--){
        cout<<l[i]<<' ';
    }
}