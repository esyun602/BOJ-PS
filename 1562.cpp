#include<bits/stdc++.h>
using namespace std;
vector<vector<long long> > v(100, vector<long long>(10,0));
int n;



int find(int t, int b){
            long long ans =0;
            int i;
            for(i=1;i<t;i++){
                for(int j=1;j<9;j++){
                    if(j==1){
                        v[i][j] = v[i-1][j+1] % 1000000000;
                    }
                    else if(j==8){
                        v[i][j] = v[i-1][j-1] % 1000000000;
                    }
                    else{
                        v[i][j] = (v[i-1][j-1]+v[i-1][j+1]) % 1000000000;
                    }
                }
            }
            if(t==0){
                i=0;
            }
            for(int j=0;j<9;j++){
                v[i][j]=0;
            }
            v[i][9] = i==0 ? 1:v[i-1][8];
            for(i+=1;i<b;i++){
                for(int j=1;j<10;j++){
                    if(j==1){
                        v[i][j] = v[i-1][j+1] % 1000000000;
                    }
                    else if(j==9){
                        v[i][j] = v[i-1][j-1] % 1000000000;
                    }
                    else{
                        v[i][j] = (v[i-1][j-1]+v[i-1][j+1]) % 1000000000;
                    }
                }
            }
           
            v[i][0] = v[i-1][1];
            for(int j=1;j<10;j++){
                v[i][j] = 0;
            }
            if(i==n-1){
                for(i=0;i<10;i++){
                    ans += v[n-1][i];
                    ans %= 1000000000;
                }
                return ans;
            }
            for(i+=1;i<n;i++){
                for(int j=0;j<10;j++){
                    if(j==0){
                        v[i][j] = v[i-1][j+1] % 1000000000;
                    }
                    else if(j==9){
                        v[i][j] = v[i-1][j-1] % 1000000000;
                    }
                    else{
                        v[i][j] = (v[i-1][j-1]+v[i-1][j+1]) % 1000000000;
                    }
                }
            }
            for(i=0;i<10;i++){
                ans += v[n-1][i];
                ans %= 1000000000;
            }
            return ans;
}



int main(){
    cin >> n;

    long long ret=0;
    long long m=0;
    long long M;
    for(int t=1;t<n-9;t++){
        for(int b=t+9;b<n;b++){
            for(int i=1;i<10;i++){
                v[0][i] = 1;
            }
            v[0][0] = v[0][9] = 0;
            ret += find(t,b);
            ret %= 1000000000;
        }
    }
    for(int b=9;b<n;b++){
        m+=find(0,b);
        m%=1000000000;
    }
    cout << ((ret*2)+m)%1000000000;
}
