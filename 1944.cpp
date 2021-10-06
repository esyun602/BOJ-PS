#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

typedef struct unionfind{
    vector<int> parent, rank;
    unionfind(int n) : parent(n), rank(n,1){
        for(int i=0;i<n;i++)    parent[i] = i;
    }
    int find(int n){
        if(n == parent[n])  return n;
        return parent[n] = find(parent[n]);
    }
    void merge(int n, int m){
        //errorp
        n = find(n);
        m = find(m);
        //errorp    
        if(find(n) == find(m))
            return;
        if(rank[n]>rank[m]) swap(n,m);
        parent[n] = parent[m];
        if(rank[n] == rank[m])
            rank[m]++;
    }
}unionfind;

vector<pair<int, int> > key;
vector<pair<int, pair<int, int> > > edge;
pair<char, int> board[60][60];
queue<pair<int, int> > q;

int main(){
    int n;
    int m;
    char k;
    int tmp=0;
    int si, sj;
    
    
    scanf("%d%d", &n,&m);
    unionfind uf(2500);
    int visited[250][250] = {};
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            k = getchar();
            if(k=='K'){
                board[i][j] = {k,tmp};
                tmp++;
                key.push_back({i,j});
            }
            else if(k=='S'){
                board[i][j] = {'K',tmp};
                tmp++;
                key.push_back({i,j});
            }
            else{
                board[i][j] = {k,0};
            }
        }
        getchar();
    }
    for(int i=0;i<key.size();i++){
        int cnt = 0;
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                visited[k][j] = 0;
            }
        }
        q.push(key[i]);
        while(!q.empty()){
            si = q.front().first;
            sj = q.front().second;
            q.pop();
            if(board[si][sj].first == 'K' && board[si][sj].second != board[key[i].first][key[i].second].second){
                edge.push_back({ visited[si][sj], { board[key[i].first][key[i].second].second, board[si][sj].second}});
                cnt++;
            }
            for(int j=0;j<4;j++){
                int nexti = si+di[j];
                int nextj = sj+dj[j];
                if(!visited[nexti][nextj] && board[nexti][nextj].first!='1'){
                    visited[nexti][nextj] = visited[si][sj]+1;
                    q.push({nexti, nextj});
                }
            }
        }
        if (cnt != key.size()-1) {
            printf("-1\n", cnt);
            return 0;
        }
    }
    sort(edge.begin(), edge.end());
    int ret= 0;
    for(int i=0;i<edge.size();i++){
        int w = edge[i].first;
        int ni = edge[i].second.first;
        int nj = edge[i].second.second; 
        if(uf.find(ni)!=uf.find(nj))    {uf.merge(ni,nj); ret+=w;}
    }
    printf("%d\n", ret);
}
