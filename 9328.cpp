#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int di[4] = {-1,0,1,0};
int dj[4] = {0,1,0,-1};

int main(){
    int tc;
    cin>>tc;
    while(tc-->0){
        bool haveKey[26] = {};
        bool visited[105][105] = {};
        char board[105][105] = {};
        vector<pii> notOpened[26];
        queue<pii> q;
        int h, w;
        string keys;
        int cnt=0;
        cin>>h>>w;
        getchar();
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                board[i][j] = getchar();
            }
            getchar();
        }
        cin>>keys;
        if(keys[0]!='0'){
            for(int i=0;i<keys.length();i++){
                haveKey[keys[i]-'a'] = true;
            }
        }
        for(int i=1;i<=h;i++){
            for(int j=1;j<=w;j++){
                if(i==1 || i==h || j==1 || j==w){
                    if(board[i][j] == '.'){
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
                    else if(board[i][j] == '$'){
                        q.push({i,j});
                        cnt++;
                        visited[i][j] = 1;
                    }
                    else if(board[i][j]>= 'A' && board[i][j] <= 'Z'){
                        if(haveKey[board[i][j]-'A']){
                            q.push({i,j});
                            visited[i][j] = 1;
                        }
                        else{
                            notOpened[board[i][j]-'A'].push_back({i,j});
                            visited[i][j] = 1;
                        }
                    }
                    else if(board[i][j]>='a' && board[i][j]<='z'){
                        q.push({i,j});
                        if(!haveKey[board[i][j]-'a']){
                            haveKey[board[i][j]-'a'] = true;
                            for(pii& k : notOpened[board[i][j]-'a']){
                                q.push(k);
                            }
                        }
                        visited[i][j] = 1;
                    }
                } 
            }
        }



        while(!q.empty()){
            pii tmp = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                pii next = {tmp.first+di[i], tmp.second+dj[i]};
                char nextVal = board[next.first][next.second];
                if(nextVal == 0 || nextVal == '*' || visited[next.first][next.second])
                    continue;
                else if(nextVal != '.'){
                    if(nextVal == '$'){
                        cnt++;
                        q.push(next);
                    }
                    else if(nextVal>= 'A' && nextVal <= 'Z'){
                        if(haveKey[nextVal-'A']){
                            q.push(next);
                        }
                        else{
                            notOpened[nextVal-'A'].push_back(next);
                        }
                    }
                    else{
                        q.push(next);
                        if(!haveKey[nextVal-'a']){
                            haveKey[nextVal-'a'] = true;
                            for(pii& j : notOpened[nextVal-'a']){
                                q.push(j);
                            }
                        }
                    }
                }
                else{
                    q.push(next);
                }
                visited[next.first][next.second] = true;
            }
        }
        cout<<cnt<<'\n';
    }
}