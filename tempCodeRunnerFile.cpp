#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int,int> pii;

pii points[100000];

bool comp(pii& a, pii& b){
    return a.second<b.second;
}

int calcDist(pii& a, pii& b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

int findMin(int start, int end){
    if(end-start<=2){
        int m=0xfffffff;
        for(int i=start;i<end;i++){
            for(int j=i+1;j<=end;j++){
                m = min(m,calcDist(points[i], points[j]));
            }
        }
        return m;
    }
    int mid = (start+end)/2;
    int minv = min(findMin(start,mid), findMin(mid+1, end));
    int margin = minv;
    vector<pii> v;
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