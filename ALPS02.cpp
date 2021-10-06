#include<bits/stdc++.h>

using namespace std;

int changeTo10(char a[], int n){
    int ret=0;
    int sub;
    for(int i=0;i<strlen(a);i++ ){
        if(a[i]>'9' || a[i]<'0'){
            sub = a[i]-'A'+10;
        }
        else{
            sub = a[i]-'0';
        }
        ret = n*ret+(sub);
    }
    return ret;
}
int findmin(char a[]){
	int ret=-1;
	int sub;
	for(int i=0;i<strlen(a);i++){
		if(a[i]>'9' || a[i]<'0'){
            sub = a[i]-'A'+10;
        }
        else{
            sub = a[i]-'0';
        }
        ret = max(ret,sub);
	}
	return ret;
}

int main(){
    char a[10], b[10], c[10];
    int l,n,m;
    char op;
    scanf("%s %s %s %c", a,b,c,&op);
    int x=max(findmin(a)+1,2);
    int y=max(findmin(b)+1,2);
    int z=max(findmin(c)+1,2);
    switch(op){
        case '+':
            for(int i=x;i<17;i++){
                l=changeTo10(a,i);
                for(int j=y;j<17;j++){
                	m=changeTo10(b,j);
                	for(int k=z;k<17;k++){
                		n=changeTo10(c,k);
                		if(l+m==n&&i!=j && j!=k && i!=k){
		                    printf("%d %d %d", i,j,k);
		                    return 0;
		                }
					}
				}
            }
            printf("-1");
            return 0;
        case '-':
            for(int i=x;i<17;i++){
                l=changeTo10(a,i);
                for(int j=y;j<17;j++){
                	m=changeTo10(b,j);
                	for(int k=z;k<17;k++){
                		n=changeTo10(c,k);
                		if(l-m==n&&i!=j && j!=k && i!=k){
		                    printf("%d %d %d", i,j,k);
		                    return 0;
		                }
					}
				}
            }
            printf("-1");
            return 0;
        case '*':
            for(int i=x;i<17;i++){
                l=changeTo10(a,i);
                for(int j=y;j<17;j++){
                	m=changeTo10(b,j);
                	for(int k=z;k<17;k++){
                		n=changeTo10(c,k);
                		if((long long)l*m==n&&i!=j && j!=k && i!=k){
		                    printf("%d %d %d", i,j,k);
		                    return 0;
		                }
					}
				}
            }
            printf("-1");
            return 0;
        case '/':
            for(int i=x;i<17;i++){
                l=changeTo10(a,i);
                for(int j=y;j<17;j++){
                	m=changeTo10(b,j);
                	if(m==0){
                		printf("-1");
                		return 0;
					}
                	for(int k=z;k<17;k++){
                		n=changeTo10(c,k);
                		if(l/m==n&&i!=j && j!=k && i!=k){
		                    printf("%d %d %d", i,j,k);
		                    return 0;
		                }
					}
				}
            }
            printf("-1");
            return 0;
        default:
        	printf("-1");
    }
}
