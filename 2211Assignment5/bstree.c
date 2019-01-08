#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include "stdlib.h"
#include "bstree.h"
#include "datatype.c"
BStree bstree_ini()
{
    BStree toReturn= calloc(1,sizeof(BStree));
    
    //    printf("%s", toReturn);
    
    
    return toReturn;
    
}



//Insert data with key into bst. If key is in bst, then do nothing.
//You may want to use a helper function for insertion to create a pointer to a tree node from key and data.

// barely understand this but ok
BStree_node *new_node(Key key, Data data)
{
    
    // believe this methos is correct actually
    BStree_node *newNode=(BStree_node*)malloc(sizeof(BStree_node));
    
    newNode->key=key;
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    
    return newNode;
}


void bst_tree_insert(BStree bst, Key key, Data data)
{
    if (*bst == NULL){
        *bst = new_node(key, data);}
    else{
        int cmp = key_comp(key, (*bst)->key);
        if (cmp < 0){
           bst_tree_insert(&(*bst)->left, key, data);}
        else if (0 < cmp){
        bst_tree_insert(&(*bst)->right, key, data);}
        else{return;}
    }
}

/*
 if((*bst)==NULL)
 printf("step one");
 (*bst) =new_node(key,data);
 key_print((*bst)->data);
 return;
 //-----
 
 if((key_comp(key, (*bst)->key))>0)
 {
 if ((*bst)->left==NULL)
 {
 //-----
 key_print((*bst)->key);
 
 (*bst)->left=new_node(key, data);
 return;
 }
 //else call function recursively if not null
 //not sure why I inserted and but ok
 
 //-----
 key_print((*bst)->key);
 
 bstree_insert(&(*bst)->left, key, data);
 
 }
 else
 {
 if ((*bst)->right == NULL)
 {
 (*bst)->right = new_node(key,data);
 //-----
 key_print((*bst)->key);
 
 return;
 }
 //-----
 key_print((*bst)->key);
 bstree_insert(&(*bst)->right,key, data);
 }
 }
 
 
 */





//If key is in bst, return key’s associated data. If key is not in bst, return NULL.
Data bstree_search(BStree bst, Key key)
{if (*bst != NULL){
        int cmp = key_comp(key, (*bst)->key);
        if (cmp < 0){
            bstree_search(&(*bst)->left, key);
        }
        else if (0 < cmp){
            bstree_search(&(*bst)->right, key);}
        else if(cmp==0){
            data_print((*bst)->data);
        }}return NULL;}






//In order traversal of bst and print each node’s key and data.

//------- TRAVERSAL -------//

void bstree_traversal(BStree bst)
{if((*bst)==NULL)
        return;{bstree_traversal(&(*bst)->left);
    key_print((*bst)->key);
data_print((*bst)->data);
bstree_traversal(&(*bst)->right);}}





//Free all the dynamically allocated memory of bst.
void bstree_free(BStree bst){
    free(bst);
}

