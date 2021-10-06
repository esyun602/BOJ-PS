#include<stdio.h>

typedef struct node{
    int data;
    struct node* leftchild;
    struct node* rightchild;
}node;

typedef struct{
    node* root;
}bst;

bst* createbst(){
    bst* ret = (bst*)malloc(sizeof(bst));
    ret->root = NULL;
    return bst;
}

void insertbst(bst* tree, int a){
    node* newnode = (node*)malloc(sizeof(node));
    node* tmp = tree->root;
    newnode->data = a;
    newnode->leftchild=NULL;
    newnode->rightchild=NULL;
    if(tmp == NULL){
        tree->root = newnode;
        return;
    }
    while(1){
        if(data>tmp->data){
            if(tmp->rightchild == NULL){
                tmp->rightchild = newnode;  
                break;
            }
            else{
                tmp = tmp->rightchild;
            }
        }
        else{
            if(tmp->leftchild == NULL)
                tmp->leftchild = newnode;
            else
                tmp = tmp->leftchild;
        }
    }
    return; 
}