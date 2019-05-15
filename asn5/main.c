#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
/**
 *Temi Owoaje, 250980280-.	
 *Main Program.
 *Program creates a mtrix using a binary search tree.
 * */

int main(void)
{

char ind1[200],ind2[200];
Value val= 1;

Matrix m = matrix_construction();// initialize matrix construction.
printf("enter 2 strings consecutively, when done entering press Ctrl D to print tree\n");
while(scanf("%s %s", ind1, ind2)==2) 
{

	unsigned char isin = matrix_isin(m, ind1, ind2);
	
	if(isin == 0)// check to see if node is in matrix.
	{
		matrix_set(m,ind1,ind2,val);// insert node into tree

	}
	else// if node is already in matrix.
	{
		matrix_inc(m,ind1,ind2,val);

	}
	
	
}

printf("String1\tSring2\tOccurrence\n");
	

matrix_list(m);// traverse the three and print out nodes with their occurence.

matrix_destruction(m);// deallocate all memory used by matrix.



}
