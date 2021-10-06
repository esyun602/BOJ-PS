#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
int added[25] = {};
double mini;
void dfs(int level, int val, pii& vect, vector<pii>& v){
    if(n/2+1-level > n-val) return;

    if(level == n/2+1){
        pii tmp = vect;
        for(int i=0;i<n;i++){
            if(!added[i]){
                //printf("%d is subtracted\n", i);
                tmp.first -= v[i].first;
                tmp.second -= v[i].second;
            }
           /* else{
                printf("%d is added\n", i);
            }*/
        }
       // printf("vector: { %d, %d }\n", tmp.first, tmp.second);
       // printf("======\n");
        mini = min(mini, sqrt(pow(tmp.first,2) + pow(tmp.second,2)));
    }
    for(int i = val;i<n;i++){
        vect.first += v[i].first;
        vect.second += v[i].second;
        added[i] = true;
        dfs(level+1, i+1, vect,v);
        vect.first -= v[i].first;
        vect.second -= v[i].second;
        added[i] = false;
    }
}



int main(){
    int t;
    cin >> t;
    while(t--){
        mini = 0xfffffff;
        pii tmp = {0,0};
        memset(added, 0, sizeof(added));
        cin >> n;
        vector<pii> v;
        for(int i=0;i<n;i++){
            int a,b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        dfs(1,0,tmp, v);
        printf("%.12lf\n", mini);

    }
}