#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> point;
typedef pair<long long,long long> Vector;
/*
실수
CCW알고리즘: 선분 교차에서 두 벡터를 기준으로 각각 계산
*/



int cross(point a, point b){
    if(a.first*b.second - a.second*b.first > 0){
        return 1;
    }
    else if(a.first*b.second - a.second*b.first == 0){
        return 0;
    }
    else return -1;
}

Vector operator-(point a, point b){
    return {a.first-b.first,a.second-b.second};
}


int main(){
    point p1,p2,p3,p4;
    cin>>p1.first>>p1.second>>p2.first>>p2.second>>p3.first>>p3.second>>p4.first>>p4.second;
    Vector v1 = p4-p3;
    Vector v2 = p1-p3;
    Vector v3 = p2-p3;
    int a = cross(v1,v2);
    int b = cross(v1,v3);
    v1 = p2-p1;
    v2 = p3-p1;
    v3 = p4-p1;
    int c = cross(v1,v2);
    int d = cross(v1,v3); 
    if(a*b<=0 && c*d<=0){
        if(a==0 && b==0){
            if((max(min(p1.first, p2.first), min(p3.first,p4.first)) <= min(max(p1.first,p2.first), max(p3.first,p4.first))) && (max(min(p1.second, p2.second), min(p3.second,p4.second)) <= min(max(p1.second,p2.second), max(p3.second,p4.second)))){
                cout<<1;
            }
            else cout<<0;
        }
        else
            cout<<1;
    }
    else
        cout<<0;
}