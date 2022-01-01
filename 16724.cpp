#include<iostream>
using namespace std;
int cnt;

void tracking(int n, int m, int nowi, int nowj, char map[][1000], int visited[][1000]){

    if(visited[nowi][nowj]==1){
        cnt++;
        visited[nowi][nowj]=2;
        return;
    }
    else if(visited[nowi][nowj]==2){
        return;
    }
    visited[nowi][nowj] = 1;
    switch(map[nowi][nowj]){
        case 'D':
            tracking(n,m,nowi+1,nowj,map,visited);
            break;
        case 'U':
            tracking(n,m,nowi-1,nowj,map,visited);
            break;
        case 'L':
            tracking(n,m,nowi,nowj-1,map,visited);
            break;
        case 'R':
            tracking(n,m,nowi,nowj+1,map,visited);
            break;
    }
    visited[nowi][nowj]=2;
}

int main(){
    char map[1000][1000];
    int visited[1000][1000]={};
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>map[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j])  continue;
            tracking(n,m,i,j,map,visited);
        }
    }
    cout<<cnt;

}