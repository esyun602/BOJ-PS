#include<bits/stdc++.h>
using namespace std;
//묶어서 처리하지 않기
//자료형 크기
 


int main(){
    int t;
    int n;
    long long cnt=0;
    cin>>t>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<int> totalSumA(n+1), totalSumB(m+1); // [0, )
    vector<int> partialSumA, partialSumB;
    totalSumA[0] = totalSumB[0] = 0;
    for(int i=1;i<n+1;i++){
        totalSumA[i] = totalSumA[i-1]+a[i-1];
    }
    for(int i=1;i<m+1;i++){
    	totalSumB[i] = totalSumB[i-1]+b[i-1];
	}
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n+1;j++){
            partialSumA.push_back(totalSumA[j] - totalSumA[i]); // [i,j)
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i+1;j<m+1;j++){
            partialSumB.push_back(totalSumB[j]- totalSumB[i]);
        }
    }
    sort(partialSumA.begin(), partialSumA.end(), less<int>() );
    sort(partialSumB.begin(), partialSumB.end(), greater<int>() );

    

    int i=0, j=0;
    while(i<partialSumA.size() && j<partialSumB.size()){
        int val = partialSumA[i]+partialSumB[j];
        if(val>t){
            j++;
        }
        else if(val<t){
            i++;
        }
        else{
            long long tmp1=1, tmp2=1;
            i++, j++;
            while(partialSumA[i]==partialSumA[i-1] && i<partialSumA.size()){
                i++;
                tmp1++;
            }
            while(partialSumB[j]==partialSumB[j-1] && j<partialSumB.size()){
                j++;
                tmp2++;
            }
            cnt += tmp1*tmp2;
        }
    }
    cout<<cnt;
}
