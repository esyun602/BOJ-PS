#include<bits/stdc++.h>
using namespace std;
vector<int> visited(100000);
vector<int> st(100000);
int cnt;
void dfs(int cur);

int main(){
    int tc;
    int stn;
    int tmp;
    scanf("%d", &tc);
    while(tc--){
        cnt =0;
        fill(visited.begin(), visited.end(), 0);
        fill(st.begin(), st.end(), 0);
        scanf("%d", &stn);
        for(int i=0;i<stn;i++){
            scanf("%d", &tmp);
            st[i] = --tmp;
        }
        for(int i=0;i<stn;i++)
            if(!visited[i])
                dfs(i);
        printf("%d\n", stn-cnt);
        
    }
}

void dfs(int cur){
    if(visited[cur]){
        if(visited[cur] == 1){
            cnt++;
            for(int i=st[cur];i!=cur;i=st[i])
                cnt++;
        }
        return;
    }
    visited[cur] = 1;
    dfs(st[cur]);
    visited[cur] = 2;
}
