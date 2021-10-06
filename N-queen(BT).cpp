#include<bits/stdc++.h>
using namespace std;
int n;
int cnt;
vector<int> q;
int visited[15];
bool permitted = true;
void queen(int lev);

void showVector(){
	for(int i=0;i<q.size();i++)
		printf("%d ", q[i]);
	printf("\n");
}

int main(){
    scanf("%d", &n);
    queen(0);
    printf("%d", cnt);
}

void queen(int lev){
    if(lev == n){
        cnt++;
        return;
    }
	   for(int i=0;i<n;i++){
        for(int j=0;j<q.size();j++){
                if(q[j]+lev-j == i || q[j] - lev+j == i)
                    permitted = false;
        }
        if(permitted && !visited[i]){
	        visited[i] = 1;
	        q.push_back(i);
	        queen(lev+1);
	        q.pop_back();
	        visited[i] =0;
        }
        permitted=true;
    }



}
