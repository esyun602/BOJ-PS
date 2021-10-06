#include<bits/stdc++.h>
using namespace std;
#define INF 1LL << 60
priority_queue <pair<long long, int> > pq;
vector <pair<int, long long> > board[100001];
int arr[100001];
long long dist[100001];
 
int main(){
    int n, m, a, b;
    pair<long long, int> tmp;
    long long val;
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    arr[n-1] = 0;
    for(int i=0;i<m;i++){
        scanf("%d %d %lld", &a, &b, &val);
        if(arr[a] == 1 || arr[b] == 1)
            continue;
        board[a].push_back(make_pair(b, val));
        board[b].push_back(make_pair(a, val));
    }
    for (int i = 0; i < n; i++)
        dist[i] = INF;
    dist[0] = 0;
    pq.push(make_pair(-dist[0], 0));
    while (!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(dist[tmp.second] != -tmp.first){
            continue;
        }
        for(int i=0;i<board[tmp.second].size();i++){
            pair<int, long long> next = board[tmp.second][i];
            if(dist[tmp.second] != INF && dist[next.first] > dist[tmp.second] + next.second){
                dist[next.first] = dist[tmp.second] + next.second;
                pq.push(make_pair(-dist[next.first],next.first));
            }
        }
    }
    if (dist[n-1] == INF){
        printf("-1");
 		return 0;
	}
    printf("%lld", dist[n-1]);
}
