#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> point;
typedef pair<int,int> vect;
int crossProduct(vect v1, vect v2){
    return v1.x*v2.y - v2.x*v1.y;
}

typedef struct line{
    point p1;
    point p2;
    vect v;

    line(point p, point pp){
        p1 = p;
        p2 = pp;
        v = {p2.x-p1.x, p2.y-p1.y};
    }
    bool isCrossed(line l){
        long long c1 = crossProduct(v,{l.p1.x - p1.x, l.p1.y-p1.y});
        long long c2 = crossProduct(v, {l.p2.x-p1.x, l.p2.y-p1.y});
        long long c3 = crossProduct(l.v, {p1.x-l.p1.x, p1.y-l.p1.y});
        long long c4 = crossProduct(l.v, {p2.x - l.p1.x, p2.y-l.p1.y});
        if(c1*c2==0 && c3*c4==0){
            return (max(l.p1.x, l.p2.x) >= min(p1.x, p2.x) && max(p1.x, p2.x) >= min(l.p1.x, l.p2.x)) && (max(l.p1.y, l.p2.y) >= min(p1.y, p2.y) && max(p1.y, p2.y) >= min(l.p1.y, l.p2.y));
        }
        else{
            return c1*c2<=0 && c3*c4<=0;
        }
    }
}line;



typedef struct unionfind{
    vector<int> parent;
    vector<int> childnum;
    unionfind(int n) : parent(n), childnum(n,1){
        for(int i=0;i<n;i++)
            parent[i] = i;
    }
    void merge(int i, int j){
        int a = find(i);
        int b = find(j);
        if(a==b)    return;
        else{
            parent[b] = a;
            childnum[a] += childnum[b];
        }
    }
    int find(int a){
        if(parent[a] == a)  return a;
        return parent[a] = find(parent[a]);
    }
}uf;


int main(){
    int n;
    cin>>n;
    uf u(n);
    vector<line> v;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        line l({a,b}, {c,d});
        v.push_back(l);
    }


    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(v[i].isCrossed(v[j])){
                u.merge(i,j);
            }
        }
    }
    int cnt=0;
    int maxi = -1;
    for(int i=0;i<n;i++){
        if(u.parent[i] == i){
            cnt++;
            maxi = max(maxi, u.childnum[i]);
        }
    }
    cout<< cnt << '\n' << maxi;
}