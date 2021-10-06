#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> v;
    int high=0;
    for(int i=0; i<n;i++ )
    {
        int k;
        cin>>k;
        v.push_back(k);
    }

    for(int i=0; i<v.size()-2; i++)
    {
        for(int j= i+1; j<v.size()-1;j++)
        {
            for(int k= j+1; k<v.size();k++)
            {
            
                if(v[i]+v[j]+v[k]<=m && v[i]+v[j]+v[k]> high)
                    high=v[i]+v[j]+v[k];
                
            }
        }
    }
    cout<<high;
}