#include<bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    vector<int> out;
    string p,t;
    getline(cin, t);
    getline(cin, p);
    int psize = p.size();
    int tsize = t.size();
    /*
    ABABCABABABCABABAB
ABABCABABAB
    */
    vector<int> pi(psize+1,0);
    pi[1] = 0;
    int i = 0;
    int j = 0;
    while(++i<psize){
        while(j>0 && p[j] != p[i]){
            j = pi[j];
        }
        if(p[j]==p[i])
            pi[i+1] = ++j;
    }
    i=0;
    int next = 0;
    while(i+psize-1<tsize){
        for(j=next;j<psize;j++){
            if(p[j] != t[i+j]){
                break;
            }
        }
        if(j==psize){
            out.push_back(i+1);
        }

        next = pi[j];
        i += max(j-pi[j],1);
    }
    cout<<out.size()<<'\n';
    for(int i=0;i<out.size();i++){
        cout<<out[i]<<' ';
    }
}