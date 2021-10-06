#include<bits/stdc++.h>
using namespace std;
int num=2;

typedef struct point{
    long long x;
    long long y;
    bool operator<(point& b){
        if(x == b.x){
            return y<b.y;
        }
        return x<b.x;
    }
}point;




void findPointNum(point &p1, point &p2, vector<point> &points, long long a, long long b, long long c){
    
    vector<point> upper;
    long long maxdist=0, maxi;
    for(int i=0;i<points.size();i++){
        if(a*points[i].x+b*points[i].y+c>0){
            upper.push_back(points[i]);
        }
        if(maxdist<a*points[i].x+b*points[i].y+c){
            maxdist = a*points[i].x+b*points[i].y+c;
            maxi = i;
        }
    }
    if(maxdist == 0){
        return;
    }
    long long a1 = p1.y-points[maxi].y, b1 = points[maxi].x-p1.x, c1 = p1.x*points[maxi].y - points[maxi].x*p1.y;
    long long a2 = -p2.y+points[maxi].y, b2 = -points[maxi].x+p2.x, c2 = -p2.x*points[maxi].y + points[maxi].x*p2.y;
    findPointNum(p1, points[maxi], upper, a1,b1,c1);
    findPointNum(points[maxi], p2, upper, a2,b2,c2);
    num++;

    
}


int main(){
    int n;
    cin>>n;
    vector<point> points(n);
    for(int i=0;i<n;i++){
        cin>>points[i].x>>points[i].y;
    }
    sort(points.begin(), points.end());
    findPointNum(points[0], points[n-1], points, points[0].y-points[n-1].y,  points[n-1].x-points[0].x,  points[0].x*points[n-1].y - points[n-1].x*points[0].y);
    findPointNum(points[n-1], points[0], points, -points[0].y+points[n-1].y,  -points[n-1].x+points[0].x,  -points[0].x*points[n-1].y + points[n-1].x*points[0].y);
    cout<<num;
}