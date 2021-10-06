#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;


int main(){
    int n, m;
    int a, b;
    int k;
    int start;
    int now;
    int desti;
    int ques[30000][2];
    int dist[251];
    int savdist[251][251];
    int arr[251][251]={};
    priority_queue<pair<int, int> > q;
    for(int i=0;i<251;i++){
        dist[i] = INF;
        for(int j=0;j<251;j++){
            arr[i][j] = savdist[i][j]=INF;
            }
    }
    scanf("%d %d", &n, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &a, &b);
        scanf("%d", &arr[a][b]);
        if(arr[a][b]==1)
            arr[b][a] = arr[a][b] = 0;
        else{
            arr[a][b] = 0;
            arr[b][a] = 1;
        }
    }
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        scanf("%d %d", &ques[i][0], &ques[i][1]);
    }
    for(int l=0;l<k;l++){
        start = ques[l][0];
        desti = ques[l][1];
        if(savdist[start][desti]!=INF){
            printf("%d\n", savdist[start][desti]);
            continue;
        }
        q.push(make_pair(0, start));
        savdist[start][start] = dist[start]= 0;
        while(!q.empty()){
            int cost = q.top().first;
            now = q.top().second;
            q.pop();
            if(dist[now]<cost)  continue;
            for(int i=1;i<n+1;i++){
                if(dist[i]>dist[now]+arr[now][i]){
                    savdist[start][i] = dist[i] = dist[now]+arr[now][i];
                    q.push(make_pair(dist[i], i));
                }
            }
        }
        printf("%d\n", dist[desti]);
        for(int j=0;j<n+1;j++){
            dist[j] = INF;
        }
    }
}
