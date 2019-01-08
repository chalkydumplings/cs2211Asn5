#include "datatype.h"
#include <string.h>
#include <stdio.h>
#include "stdlib.h"


char * string_dup(char *str)
{
    char *copy;// has memory value adress
    //dynamic memrory allocation
    //cast or there will be an error?
    //size = lenght of string * char
    
    if ((copy = malloc(strlen(str)*sizeof(char))) == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    
    
    // destination: copy, home: - string
    strcpy(copy,str);
    
    return copy;
}




//Generate a key with dynamic memory allocation.
Key key_gen(char *skey1, char *skey2)
{
    // what does _ struct means I think auto sizes or sumething
    Key key= malloc(sizeof(Key_struct));
    
    
    key->skey1=string_dup(skey1);
    key->skey2=string_dup(skey2);
    
    //printf("%s", &key);
    return key;
    
    
}









//Use strcmp( ) to do comparison. If key1->skey1 and key2->skey1 are different, then they determine the comparison result. If key1->skey1 and key2->skey1 are the same, then key1->skey2 and key2->skey2 determine the comparison result.
int key_comp(Key key1, Key key2)


{
    if(strcmp(key1->skey1,key2->skey1)!=0)
        return strcmp(key1->skey1, key2->skey1);
    else
        return strcmp(key1->skey2,key2->skey2);
    
    
}



//--- IT WORKS WOO
//Print a key.
void key_print(Key key)
{
    
    printf(" %s%s",key->skey1,key->skey2);
    
    
    
}

//Free memory allocated for key.
void key_free(Key key)
{
    free(key);
}


//Generate a data with dynamic memory allocation.
Data data_gen(int idata)

{
    Data  data=(int *)malloc(sizeof(int)*idata);
    
    *data=idata;
    
    return data;
    
    
}



void data_set(Data data, int idata){
    *data=idata;
    
    
    // de-ref data and set it to whatver you put in for data
    
}


//Print a data.
void data_print(Data data)

{
    printf("%d",*data);
}


//Free memory allocated for data.
void data_free(Data data)
{
    
    free(data);
}



//not an actual method you need

void *duplicate(char * str)
{
    char *duped_str;
    
    if ((duped_str = malloc(strlen(str) + 1)) == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    
    strcpy(duped_str, str);
    return duped_str;
}


