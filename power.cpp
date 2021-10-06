#include<bits/stdc++.h>
//범위자료형
//처음부터 기저일 때
//         '/'!='%' 
int **a;
long long b;
int n;


int** power(long long count){
    int **ret;
    int **ret2 = (int**)malloc(sizeof(int*)*5);
    for(int i=0;i<5;i++){
        ret2[i] = (int*)malloc(sizeof(int)*5);
        for(int j=0;j<5;j++){
            ret2[i][j] =  0;
        }
            
    }
     int **ret3 = (int**)malloc(sizeof(int*)*5);
    for(int i=0;i<5;i++){
        ret3[i] = (int*)malloc(sizeof(int)*5);
    } 
    
    
    
    if(count==1)
        return a;
        
    ret = power(count/2);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                ret2[i][j] += ret[i][k] * ret[k][j];
            if(ret2[i][j]>=1000){
                ret2[i][j] %= 1000;
            }
        }
    }
        
    if(count%2 == 1){
    	for(int i=0;i<n;i++)
    		for(int j=0;j<n;j++){
    			ret3[i][j] = ret2[i][j];
    			ret2[i][j] = 0;
			}
    			
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++)
                    ret2[i][j] += ret3[i][k] * a[k][j];
                if(ret2[i][j]>=1000){
                	
                ret2[i][j] %= 1000;
            	}
            }
        }
    }
    return ret2;
}



int main(){
	a = (int**)malloc(sizeof(int*)*5);
 	for(int i=0;i<5;i++){
        a[i] = (int*)malloc(sizeof(int)*5);
        
    }
    scanf("%d %lld", &n, &b);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d", &a[i][j]);
    }
    int **c;
    c = power(b);
     for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(c[i][j]>=1000){
                c[i][j] %= 1000;
            	}
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
   
}
