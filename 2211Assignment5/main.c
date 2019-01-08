#include <stdio.h>
#include "datatype.h"
#include "bstree.h"

int main(void)
{
    char *str = "jubes beauty 14 subscribe.";
    char *str2 = "poo";
    Data x=data_gen(99);
    data_print(x);
    printf("\n");
    Key y=key_gen(str, str2);
    
    
    key_print(y);
    printf("\n");
    
    
    printf("first: %s\n", str);
    printf("Duplicated String: %s\n", str2);
    
    
    
    
    printf("\n");
    
    BStree hi= bstree_ini();
    //is poo a completley diff binary search tree ???
    BStree poo=bstree_ini();
    
    printf("\n");
    Key b=key_gen("c","c");
    
    bst_tree_insert(hi,b,data_gen(1));
    printf("\n");
    // OOH IT WORKS IF U TRY TO INSERT THE SAME KEY TWICE FUCK YAH WOOO
    
    bst_tree_insert(hi,key_gen("a","a"),data_gen(2));
    //THIS WORKS WONT INSERT SAME KEY TWICE WOOOOOO
    bst_tree_insert(hi,key_gen("b","b"),data_gen(2));
    
    bst_tree_insert(hi,key_gen("b","h"),data_gen(2));
    bst_tree_insert(hi,key_gen("d","d"),data_gen(69));
    bst_tree_insert(hi,key_gen("a","b"),data_gen(69));
    bst_tree_insert(hi,key_gen("a","b"),data_gen(69));
    bst_tree_insert(hi,key_gen("e","e"),data_gen(50));
    
    
    
    
    
    key_gen("b","b");
    
    printf("\n");
    
    //Test if key already exists appears to be sucessful
    
    bstree_search(hi,b );
    printf("\n");
    // I beleive this to be sucessful but UNSURE
    bstree_search(hi,  key_gen("b","i") );
    
    
    printf("\n");
    
    // I beleive this to be sucessful but UNSURE
    bstree_search(hi,  key_gen("b","h") );
    printf("\n");
    
    bstree_traversal(hi);
    
    
    printf("\n");
    
    
    //u gotta free so it doesn't memory leak
    //segmentation fault yah that's for another day
    key_free(y);
    data_free(x);
    bstree_free(hi);
    
}


