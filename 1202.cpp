#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool cmp(const int& a,const int& b){
    return a>b;
}

bool cmp2(const pii& a, const pii& b){
    return a>b;
}
vector<pii> arr(300005);
multiset<int> bag;


int main(){
    long long ret = 0;
    int n,k;
    cin >> n >> k;
    bool visited[300005] = {};
    for(int i=0;i<n;i++){
        int m,v;
        cin >> m >> v;
        arr[i] = {v,m};
    }
    for(int i=0;i<k;i++){
        int c;
        cin >> c;
        bag.insert(c);
    }
    sort(arr.begin(), arr.end(), cmp2);
    for(int i=0;i<n;i++){
        multiset<int>::iterator iter;
        if( (iter = bag.find(arr[i].second)) == bag.end())  
            iter = bag.upper_bound(arr[i].second);
        if(iter == bag.end())    continue;
        bag.erase(iter);
        ret += arr[i].first;

    }
    cout<<ret;
}