#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include <string.h>
/**
 *Temi Owoaje, 250980280
 *Datatype.c file
 * */
// own C funtion to replicate C librrary strdup!!
char * string_dup(char *str)
{

char *newchar = (char *) malloc(1 + sizeof(strlen(str)));
strcpy(newchar,str);

return newchar;


}

// function generates a key from two strings.
Key key_gen(char *skey1, char *skey2)
{

Key newkey;
newkey =(Key)malloc(sizeof(Key_struct));// dynamically allocates memory for new key type.

newkey->skey1 = string_dup(skey1);
newkey->skey2 =  string_dup(skey2);


return newkey; 

}

// function compares two keys.
int key_comp(Key key1, Key key2) {

int n;

n= strcmp(key1->skey1,key2->skey1);

if(n ==0)
{
	n=strcmp(key1->skey2,key2->skey2);

}

return n;
}

/**
 * function prints key.
 * */
void key_print(Key key) {


printf("%s\t%s\t", key->skey1, key->skey2);

}

// free all memory used by key
void key_free(Key key) {


free(key);

}

/**
 * Generates data giving an integer.
 * */
Data data_gen(int idata)
{
	Data newdata;
	newdata = malloc(sizeof(Data));

	*newdata = idata;

	return newdata;

}
/**
 * sets given data to new idata.
 *
 * */

void data_set(Data data, int idata)
{

	*data = idata;

}
// print the associated data
void data_print(Data data)
{

printf("%d\n",*data);


}
// free all memory used by data.
void data_free(Data data)
{
	
	free(data);

}



