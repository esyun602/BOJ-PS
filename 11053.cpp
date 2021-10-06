#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> l;
    while(n--){
        int a;
        cin>>a;
        if(l.empty() || l[l.size()-1] < a){
            l.push_back(a);
        }
        else{
            *lower_bound(l.begin(), l.end(), a) = a;
        }
    }
    cout<<l.size();
}