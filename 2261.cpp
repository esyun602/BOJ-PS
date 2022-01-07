#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<long long,long long> pll;

pll points[100000];

bool comp(pll& a, pll& b){
    return a.second<b.second;
}

long long calcDist(pll& a, pll& b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int findMin(int start, int end){
    if(end-start<=2){
        long long m=0xfffffffffffffff;
        for(int i=start;i<end;i++){
            for(int j=i+1;j<=end;j++){
                m = min(m,calcDist(points[i], points[j]));
            }
        }
        return m;
    }
    int mid = (start+end)/2;
    long long minv = min(findMin(start,mid), findMin(mid+1, end));
    long long margin = minv;
    vector<pll> v;
    for(int i = mid; i>=start && (points[mid].first-points[i].first)*(points[mid].first-points[i].first) < margin; i--){
        v.push_back(points[i]);
    }
    for(int i=mid+1;i<=end && (points[i].first - points[mid].first)*(points[i].first-points[mid].first) < margin; i++){
        v.push_back(points[i]);
    }
    sort(v.begin(), v.end(), comp);
    margin = minv;
    for(int i=0; i<(int)v.size()-1; i++){
        for(int j=i+1;j<v.size();j++){
            if(v[j].second - v[i].second < margin){
                minv = min(minv, calcDist(v[i], v[j]));
                margin = minv;
            }
            else{
                break;
            }
        }
    }
    return minv;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        points[i] = {x,y};
    }
    sort(points, points+n);
    cout<<findMin(0,n-1);


}