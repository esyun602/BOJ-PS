#include<bits/stdc++.h>
using namespace std;
int n, k;
int cntAll;
int cntAns;
double num[15];
int num2[15];
int digits[15];
bool visited[15];
int sumDigit;
int summ;
vector<int> order;
int digit(int n){
    int cnt=0;
    while(n!=0){
        n/=10;
        cnt++;
    }
    return cnt;
}
int mpow(int num, int count){
    if(count==0){
        return 1;
    }
    int ret = mpow(num, count/2);
    ret *= ret;
    if(count%2 == 1){
        ret *= num;
    }
    ret %= k;
    return ret;
}


void p(){
    if(!order.empty()&&order.size() == n){
        sumDigit = 0;
        for(int i=0;i<n;i++){
            num2[i] = fmod((num[order[i]]*mpow(10, sumDigit)),k);
            sumDigit += digits[order[i]];
        }
        summ = 0;
        for(int i=0;i<n;i++){
            summ += num2[i];
        }
        if(summ%k == 0){
            cntAns++;
        }
        cntAll++;
        return;
    }

    for(int i=0;i<n;i++){
    	if(!visited[i]){
        order.push_back(i);
        visited[i] = true;
        p();
        visited[i] = false;
        order.pop_back();
    }
    }
}


int main(){
    
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%lf", &num[i]);
        digits[i] = digit(num[i]);
    }
    scanf("%d", &k);
    for(int i=0;i<n;i++){
        num[i] = fmod(num[i], k);
    }
    p();
    if(cntAns==0){
    	printf("0/1");
    	return 0;
	}
    for(int i=1;i<=cntAns;i++){
    	if(cntAns%i==0 && cntAll%i == 0){
    		cntAns/=i;
    		cntAll /= i;
    		i=1;
		}
	}
    printf("%d/%d", cntAns, cntAll);
    
}
