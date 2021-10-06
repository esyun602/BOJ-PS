#include<bits/stdc++.h>
using namespace std;

int dp[1000];
string dp2[1000];
int findMin[1000][26];

int main(){
    
    string a,b;
    cin>>a>>b;
    int lena = a.length();
    int lenb = b.length();
    for(int i=0;i<26;i++){
        findMin[lenb-1][i] = b[lenb-1] - 'A' == i ? lenb-1 : -1;
        for(int j=lenb-2;j>=0;j--){
            if(b[j]-'A' == i){
                findMin[j][i] = j;
            }
            else{
                findMin[j][i] = findMin[j+1][i];
            }
        }
    }
    for(int i=0;i<lena;i++){
    	int here = a[i]-'A';
        for(int j=lenb-2;j>=0;j--){
        	if(findMin[j+1][here] != -1 && dp[j]+1 > dp[findMin[j+1][here]]){
        		dp[findMin[j+1][here]] = dp[j]+1;
        		dp2[findMin[j+1][here]] = dp2[j]+a[i];
			}
		}
		if(b[0] == a[i] && dp[0] == 0){
			dp[0] = 1;
			dp2[0] = a[i];
		}
    }
    int maxi = -1;
    int maxindex = -1;
    for(int i=0;i<lenb;i++){
        if(maxi<dp[i]){
            maxi = dp[i];
            maxindex = i;
            //cout<<"i"<<i<<"maxi"<<maxi<<'\n';
        }
    }
    cout<<maxi<<'\n';
    if(maxi!=0)
        cout<<dp2[maxindex];
        /*for(int i=0;i<a.length();i++){
        for(int j=0;j<2;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<'\n';
    }*/
}