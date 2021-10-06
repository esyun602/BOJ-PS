#include<bits/stdc++.h>
using namespace std;
int a[500001] = {};
int p[500001];

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    
    memset(p, -1, sizeof(p));
    vector<int> ret;
    vector<int> l;
    int last = -1;
    int val = 0;
    int m = -1;
    cin>>n;
    for(int i=0;i<n;i++){
        int c,b;
        cin>>c>>b;
        a[c] = b;
        m = max(m,c);
        m = max(m,b);
    }

    for(int i=1;i<=m;i++){
        if(a[i]==0) continue;
        if(l.empty() || l[l.size()-1] < a[i]){
            l.push_back(a[i]);
            last = i;
            p[i] = l.size()-1;
        }
        else{
            vector<int>::iterator j = lower_bound(l.begin(), l.end(), a[i]);
            *j = a[i];
            p[i] = j-l.begin();
        }
    }

    val = n-l.size();
    int cnt = l.size()-2;
    for(int i=last-1;i>=1;i--){
        if(p[i]==-1) continue;
        if(p[i] == cnt && cnt!=-1){
            cnt--;
        }
        else{
            ret.push_back(i);
        }
    }
    for(int i=last+1;i<=m;i++){
        if(a[i]==0) continue;
        ret.push_back(i);
    }
    sort(ret.begin(), ret.end());
    cout<<val<<'\n';
    for(int i=0;i<ret.size();i++)
        cout<<ret[i]<<'\n';

}