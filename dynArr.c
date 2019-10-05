#include <assert.h>
#include <stdlib.h>
#include "dynArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/*************************************************************************
 * 	Dynamic Array Functions
 *************************************************************************/

/* Initialize (including allocation of data array) dynamic array.
 * param: 	v	pointer to the dynamic array
 * param:	cap 	capacity of the dynamic array
 * pre:		v is not null
 * post:	internal data array can hold cap elements
 * post:	v->data is not null
 */
void initDynArr(DynArr *v, int capacity) {
   assert(capacity > 0);
   assert(v!= 0);

   v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
   assert(v->data != 0);

   v->size = 0;
   v->capacity = capacity;	
}

/* Allocate and initialize dynamic array.
 * param:	cap 	desired capacity for the dyn array
 * pre:		none
 * post:	none
 * ret:		a non-null pointer to a dynArr of cap capacity
 * 		and 0 elements in it.		
 */
DynArr* newDynArr(int cap) {
   assert(cap > 0);

   DynArr *r = (DynArr *)malloc(sizeof( DynArr));
   assert(r != 0);

   initDynArr(r,cap);
   return r;
}

/* Deallocate data array in dynamic array. 
 * param: 	v	pointer to the dynamic array
 * pre:		none
 * post:	data points to null
 * post:	size and capacity are 0
 * post:	the memory used by v->data is freed
 */
void freeDynArr(DynArr *v) {
   if(v->data != NULL) {
      free(v->data); 	// free the space on the heap
      v->data = NULL; // make it point to null
   }

   v->size = 0;
   v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure. 
 * param: 	v		pointer to the dynamic array
 * pre:		none
 * post:	the memory used by v->data is freed
 * post:	the memory used by d is freed
 */
void deleteDynArr(DynArr *v) {
   freeDynArr(v);
   free(v);
}

/* Resizes the underlying array to be the size cap 
 * param: 	v	pointer to the dynamic array
 * param:	cap	the new desired capacity
 * pre:		v is not null
 * post:	v has capacity newCap
 */
void _dynArrSetCapacity(DynArr *v, int newCap) {
   assert(v != 0);

   TYPE* holder = (TYPE*)malloc(sizeof(TYPE) * newCap);
   assert(holder != 0);

   for (int index = 0; index < v->size; index++) {
      holder[index] = v->data[index];
   }

   free(v->data);
   v->data = holder;
}

/* Get the size of the dynamic array
 * param: 	v	pointer to the dynamic array
 * pre:		v is not null
 * post:	none
 * ret:		the size of the dynamic array
 */
int sizeDynArr(DynArr *v) {
   return v->size;
}

/* Adds an element to the end of the dynamic array
 * param: 	v	pointer to the dynamic array
 * param:	val	the value to add to the end of the dynamic array
 * pre:		the dynArry is not null
 * post:	size increases by 1
 * pre:		if reached capacity, capacity is doubled
 * post:	val is in the last utilized position in the array
 */
void addDynArr(DynArr *v, TYPE val) {
   assert(v != 0);

   if (v->size >= v->capacity) {
      _dynArrSetCapacity(v, v->capacity * 2);
   }

   v->data[v->size] = val;
   v->size++;
}
