#include<bits/stdc++.h>
using namespace std;
int ori;
int num;
int tmp; 
int broken[10] = {};

int lent(int tmp){
	if(tmp == 0)
		return 1;
	int len=0;
	while (tmp!=0)
    {
        tmp/=10;
        len++;
    }
    return len;
}
bool possible(int tmp){
	int ret = !broken[tmp%10];
	while(tmp!=0){
		ret &= !broken[tmp%10];
		tmp/=10;
	}
	return ret;
	
}
int main(){
    
    int len=0;
    int togo = 0;
    scanf("%d", &ori);
    scanf("%d", &num);
    while(num--){
        scanf("%d", &tmp);
        broken[tmp] = true;
    }
    for(int i=0; ori-i>=0 || ori+i<=1000000;i++){
		if(ori-i>=0 && possible(ori-i)){
			printf("%d", min(abs(ori-100), i+lent(ori-i)));
			return 0;
		}
		if(ori+i<=1000000 && possible(ori+i)){
    		printf("%d", min(abs(ori-100), i + lent(ori+i)));
    		return 0;
		}
	}
	printf("%d", abs(ori-100));
}
