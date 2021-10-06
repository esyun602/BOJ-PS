#include<bits/stdc++.h>


//2중 for 에서 break X
// 대소문자 



using namespace std;
char arr[100][100];
int r,c;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};


void throwStick(int direction, int height){
    vector<pair<int, int> > cluster;
    bool moved[100][100] = {};
    bool visited[100][100] = {};
    bool floor = false;
    queue<pair<int, int> > q;
    pair<int, int> tmp;
    int nexti;
    int nextj;
    bool checked = 0;
    if(direction==0){
        for(int i=0;i<c;i++){
            if(arr[height][i] == 'x'){
                arr[height][i] = '.';
                break;
            }
        }
    }
    else{
        for(int i=c-1;i>=0;i--){
        	
            if(arr[height][i] == 'x'){
                arr[height][i] = '.';
                break;
            }
        }
    }
    
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]=='.')
                visited[i][j] = 1;
                
        }
    }
    while(1){
        for(int i=0;!checked&&i<r;i++){
            for(int j=0;j<c;j++){
                if(!visited[i][j]){
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                    cluster.push_back(make_pair(i, j));
                    checked = 1;
                    break;
                }
				else if(i==r-1 && j==c-1){
                    return;
                }
            }
        }
        checked = 0;
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            if(tmp.first == r-1)
                floor = 1;
            for(int i=0;i<4;i++){
                nexti = tmp.first + di[i];
                nextj = tmp.second + dj[i];
                if(nexti<r && nexti >=0 && nextj<c && nextj >= 0){
                    if(!visited[nexti][nextj] && arr[nexti][nextj] == 'x'){
                        visited[nexti][nextj] = 1;
                        q.push(make_pair(nexti, nextj));
                        cluster.push_back(make_pair(nexti, nextj));
                    }
                }
            }
        }
        
        
        while(!floor){
            for(int i=0;i<cluster.size(); i++){
                if(!moved[cluster[i].first][cluster[i].second])
                    arr[cluster[i].first][cluster[i].second] = '.';
                arr[cluster[i].first+1][cluster[i].second] = 'x';
                moved[cluster[i].first+1][cluster[i].second] = true;
                cluster[i].first += 1;
            }
            for(int i=0;i<cluster.size();i++){
                if(cluster[i].first == r-1){
                    return;
                }
                if(arr[cluster[i].first+1][cluster[i].second]=='x'){
                    for(int j=0;j<cluster.size();j++){
                        if(cluster[j] == make_pair(cluster[i].first+1, cluster[i].second)){
                            checked = 1;
                        }
                    }
                    if(!checked)
                    	return;
                    checked = 0;
                }
            }
            for(int i=0;i<r;i++)
            	for(int j=0;j<c;j++)
            		moved[i][j] = false;
        }
        cluster.clear();
        floor = 0;
    }

}



int main(){
    
    int n, h;
    scanf("%d %d", &r, &c);
    getchar();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &h);
        throwStick(i%2,r-h);
    
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}
