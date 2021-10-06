#include<bits/stdc++.h>
using namespace std;
char arr[50][50];
int visited[50][50][2];
int spinned[50][50];
int n;
bool canSpin(int i, int j){
    int nexti, nextj;
    int dia[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dja[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        for(int k=0;k<8;k++){
            nexti = i+dia[k];
            nextj = j+dja[k];
            if(nexti<0 || nextj<0 || nexti>=n || nextj>=n || arr[nexti][nextj] == '1')
                return false;
        }
        return true;
}

int main(){
    int di[4] = {-1, 0, 1, 0};
    int dj[4] = { 0, 1, 0, -1};
    int count = 0;
    int tmp=0;
    int front;
    int tale;
    int state;
    int posi, posj;
    int nexti, nextj;
    int goali, goalj, goals;
    queue<pair<pair<int, int>, int> > q;
    queue<pair<pair<int, int>, int> > nextq;
    scanf("%d", &n);
    getchar();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%c", &arr[i][j]);
            }
        getchar();
    }
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]=='B' && count == 0){
                count++;
                if(i!=n-1 && arr[i+1][j] == 'B'){
                    q.push(make_pair(make_pair(i+1, j), 0));
                    visited[i+1][j][0] = 1;
                }
                else{
                     q.push(make_pair(make_pair(i, j+1), 1));
                     visited[i][j+1][1] = 1;
                     }
            }
              if(arr[i][j]=='E' && tmp == 0){
                tmp++;
                if(i!=n-1 && arr[i+1][j] == 'E'){
                    goali = i+1;
                    goalj = j;
                    goals = 0;
                }
                else{
                    goali = i;
                    goalj = j+1;
                    goals = 1;
                }
		}
	}
}
    count = 0;
    while(!q.empty()){
        posi = q.front().first.first;
        posj = q.front().first.second;
        state = q.front().second;
        
        printf("i: %d, j: %d, state: %d\n", posi, posj, state);
        q.pop();
        if(posi == goali && posj == goalj && state == goals){
            printf("%d", count);
            return 0;
        }
        for(int i=0;i<4;i++){
            nexti = posi+di[i];
            nextj = posj+dj[i];
            if(state == 1){
                if(nexti>=0 && nextj-1>=0 && nexti<n && nextj+1<n){
                    if(arr[nexti][nextj+1] != '1' && arr[nexti][nextj-1] != '1' && arr[nexti][nextj]!='1' && !visited[nexti][nextj][1]){
                        nextq.push(make_pair(make_pair(nexti, nextj), state));
                        visited[nexti][nextj][1] =1;
                    }
                }
            }
            if(state == 0){
                if(nexti-1>=0 && nextj>=0 && nexti+1<n && nextj<n){
                    if(arr[nexti+1][nextj] != '1' && arr[nexti-1][nextj] != '1'&& arr[nexti][nextj] !='1' && !visited[nexti][nextj][0]){
                        nextq.push(make_pair(make_pair(nexti, nextj), state));
                        visited[nexti][nextj][0] =1;
                    }
                }
            }
            
        }
		if(!visited[posi][posj][!state]&&canSpin(posi, posj)){
                nextq.push(make_pair(make_pair(posi, posj), !state));
                visited[posi][posj][!state] = 1;
        }
        if(q.empty()){
            swap(q, nextq);
            count++;
            printf("c: %d\n", count);
        }
    }
    printf("0");
}
