#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
//실수
//
//else if 에서의 조건 고려
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
int mp[1005][1005];//mp[1][m] ->> mp[n][1]
bool visited[1005][1005][2]={};
int main(){
    int n,m;
    int cnt=0;
    int ret = -1;
    cin>>n>>m;
    getchar();
    pii goal = {n,m};
    
    memset(mp, -1, sizeof(mp));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char a = getchar();
            mp[i][j] = a-'0';
        }
        getchar();
    }

    queue<pair<pii, int>> q;
    queue<pair<pii, int>> q2;
    q2.push({{1,1},1});
    while(!q2.empty()){
        cnt++;
        swap(q,q2);
        while(!q.empty()){
            pair<pii,int> here = q.front();
            q.pop();
            if(here.first == goal){
                ret = cnt;
                q2 = queue<pair<pii,int>>();
                break;
            }
            for(int i=0;i<4;i++){
                pii next = {here.first.first+di[i], here.first.second + dj[i]};
                int nextval = mp[next.first][next.second];
                if(nextval == -1 || nextval == 1 && here.second==0){
                    continue;
                }
                else if(nextval == 1 && !visited[next.first][next.second][0]){
                    q2.push({next, 0});
                    visited[next.first][next.second][0] = true;
                }
                else if(nextval == 0 && !visited[next.first][next.second][here.second]){
                    q2.push({next, here.second});
                    visited[next.first][next.second][here.second] = true;
                }
            }

        }
    }
    cout<<ret;
}