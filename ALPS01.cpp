#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    char str[200];
    char out[250];
    int Mspace=-1;
    int tmp=0;
    scanf("%d", &a);
    getchar();
    scanf("%s", str);
    for(int i=0;i<a;i++){
        if(str[i]=='_'){
            tmp = 0;
            while(str[i]=='_'){
                tmp++;
                i++;
            }
            Mspace = max(Mspace,tmp);
        }
    }
    for(int i=0;i<a;i++){
        if(str[i]=='_'){
            while(str[i]=='_')
                i++;
            for(int j=0;j<Mspace;j++)
                printf("_");
        }
        printf("%c", str[i]);
    }
}
