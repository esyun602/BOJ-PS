#include<iostream>
#include<vector>
using namespace std;

class unionfind{
    public:
        vector<int> parent;
        unionfind(int n) : parent(n){
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int find(int a){
            if(parent[a] == a){
                return a;
            }
            return parent[a] = find(parent[a]);
        }
        void unify(int a, int b){
            a = find(a), b=find(b);
            parent[b] = a;
        }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    int ret=0;
    bool cycle = false;
    cin>>n>>m;
    unionfind uf(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(!cycle && uf.find(a) == uf.find(b)){
            ret = i+1;
            cycle = true;
        }
        uf.unify(a,b);
    }
    cout<<ret;
}