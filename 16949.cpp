#include<iostream>
#include<cstdbool>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};
int n,m;

    pii mcount[1000][1000]={};
    char map[1000][1000];
    bool visited[1000][1000]={};
void bfs(int x, int y, pii mcount[][1000], char map[][1000], bool visited[][1000], int sign){
    int cnt = 0;
    queue<pii> q;
    queue<pii> record;
    q.push({y,x});
    visited[y][x]=1;
    record.push({y,x});
    while(!q.empty()){
        pii tmp = q.front();
        q.pop();
        cnt++;
        for(int i=0;i<4;i++){
            if(tmp.second+dj[i]>m-1 || tmp.first+di[i]>n-1 || tmp.second+dj[i]<0 || tmp.first+di[i]<0)
                continue;
            int nexti = tmp.first+di[i], nextj = tmp.second+dj[i];
            if(visited[nexti][nextj] || map[nexti][nextj] == '1')
                continue;
            visited[nexti][nextj]=true;
            q.push({nexti,nextj});
            record.push({nexti,nextj});
        }
    }
    while(!record.empty()){
        pii tmp = record.front();
        record.pop();
        mcount[tmp.first][tmp.second] = {cnt,sign};
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int g=1;
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]||map[i][j]=='1')   continue;
            bfs(j,i,mcount,map,visited,g++);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]=='0'){
                cout<<0;
            }
            else{
                int ret=0;
                pii record[4]={};
                for(int k=0;k<4;k++){
                    if(j+dj[k]>m-1 || i+di[k]>n-1 || j+dj[k]<0 || i+di[k]<0)
                        continue;
                    record[k]=mcount[i+di[k]][j+dj[k]];
                }
                ret+=record[0].first;
                if(record[1].second!=record[0].second){
                    ret+=record[1].first;
                }
                if(record[2].second!=record[1].second && record[2].second != record[0].second){
                    ret+=record[2].first;
                }
                if(record[3].second!=record[2].second && record[3].second!=record[1].second && record[3].second != record[0].second){
                    ret+=record[3].first;
                }
                cout<<(ret+1)%10;
            }
        }
        cout<<'\n';
    }
}