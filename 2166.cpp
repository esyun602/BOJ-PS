#include<bits/stdc++.h>
using namespace std;
class point{
    public:
        long long x;
        long long y;
    point(int x, int y){
        this->x = x;
        this->y = y;
    }
};

typedef point vect;


vect operator-(vect a, vect b){
    return vect(a.x-b.x, a.y-b.y);
}

long long crossProductScale(vect v1, vect v2){
    return (v1.x*v2.y - v1.y*v2.x);
}

int main(){
    double area;
    int n;
    cin>>n;
    vector<point> v;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x>>y;
        v.push_back(point(x,y));
    }
    point p1 = v[0];
    for(int i=1;i<n-1;i++){
        point p2 = v[i];
        point p3 = v[i+1];
        area += (crossProductScale(p2-p1, p3-p1));
    }
    area /= 2;
    area = abs(area);
    printf("%.1lf", area);

}
