#include<bits/stdc++.h>
using namespace std;

int len[1000000];
long long sum;
int sol=-1;
int s, c;
long long sumlen;
void binsearch(int left, int right){
    int mid = (left+right)/2;
    printf("left: %d right: %d mid: %d\n", left, right, mid);
    sum = 0;
    if(mid==0){
    	sol = 1;
    	return;
	}
	for(int i=0;i<s;i++){
        sum+= len[i]/mid;
    }
    if(left>=right){
    	if(sum>=c)
			sol = mid;
		return;	
	}
    

 
    if(sum<c){
        binsearch(left, mid-1);
    }
    else{
    	sol = mid;
        binsearch(mid+1, right);
    }
}

int main(){
    scanf("%d %d", &s, &c);
    for(int i=0;i<s;i++){
        scanf("%d", &len[i]);
        sumlen+=len[i];
    }
    binsearch(0, 1000000000);
    printf("%lld", sumlen-(long long)sol*c);
}
