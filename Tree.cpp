#include<bits/stdc++.h>
using namespace std;

typedef struct linkedlist{
    char alp;
    linkedlist * right;
    linkedlist * left; 
}ls;
vector<char> adj[26];



void preOrder(char a){
    if(a == '.')
        return;

    printf("%c", a);
    preOrder(adj[a-'A'][0]);
    preOrder(adj[a-'A'][1]);
}
void inOrder(char a){
    if(a == '.')
            return;

        
        inOrder(adj[a-'A'][0]);
        printf("%c", a);
        inOrder(adj[a-'A'][1]);
}
void postOrder(char a){
     if(a == '.')
        return;

    
    postOrder(adj[a-'A'][0]);
    postOrder(adj[a-'A'][1]);
    printf("%c", a);
}


int main(){
    int n;
    char a, b, c;
    scanf("%d", &n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c %c %c", &a, &b, &c);
        adj[a-'A'].push_back(b);
        adj[a-'A'].push_back(c); 
        getchar();
    }
    preOrder('A');
    printf("\n");
    inOrder('A');
    printf("\n");
    postOrder('A');
    printf("\n");
}
