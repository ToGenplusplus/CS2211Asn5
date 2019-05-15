#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
/**
 * Temi Owoaje, 250980280
 *Matrix.c 
 *Constructs matrix using functions from bstree.
 *
 * */
Matrix matrix_construction(void)
{
	BStree bst;
	bst= bstree_ini();
	return bst;

}
/**
 *If location (index1, index2) is defined in Matrix m, then return 1. Otherwise, return 0.
*/
unsigned char  matrix_isin(Matrix m, Index index1, Index index2)
{
	Key newkey = key_gen(index1,index2);
	Data search = bstree_search(m,newkey);
	if(search != NULL)// if tree isn't empty
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

// returns a pointer to the associated
//value if the locations is in matrix. Otherwise, return NULL.
//
Value *matrix_get(Matrix m, Index index1, Index index2)
{
	Key newkey = key_gen(index1,index2);
        Value search = bstree_search(m,newkey);
	
        if(search != NULL)
        {
                Value *val;
		val = search;
		return val;// returns pointer to associated index values
        }
        else
        {
                return search;// return null
        }


}

//Assigns value to Matrix m at location (index1, index2). If that location already has value it overwrites the value.
void matrix_set(Matrix m, Index index1, Index index2, Value value)

{
	Key newkey = key_gen(index1,index2);
	Data search= bstree_search(m,newkey);
	if(search == NULL)// if key is not in the tree.
	{	
		Data dat = data_gen(value);
		bstree_insert(m,newkey,dat);
	}
	else
	{
		
		data_set(search, value);// replace old value, with new value.
	
	}	


}


//If location (index1, index2) is defined in Matrix m, then the associated value is increased by
//value. Otherwise it reports error
void matrix_inc(Matrix m, Index index1, Index index2, Value value)
{

	Key newkey = key_gen(index1,index2);
        Data search = bstree_search(m,newkey);// get associated index value

        if(search != NULL)
        {
                search = matrix_get(m, index1, index2);// get the value of associated indexes.
	 	Data dat = data_gen(*search);// generates a data object from a given integer	
		data_set(dat,*search + value);// sets data to val plus given value.
		matrix_set(m,index1,index2,*dat);
	
        }
        else// display error.
        {
                printf("error: (%s,%s) not definded in matrix",index1,index2);
        }



}
// prints the contenets of a given matrix
void matrix_list(Matrix m)
{

	bstree_traversal(m);
}

//deallocates space created by matrix
void matrix_destruction(Matrix m)
{


	bstree_free(m);


}
