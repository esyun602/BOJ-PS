#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n;
    cin>>n;
    vector<vector<pii>> v(n+1);
    for(int i=1;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){

    }
    
}