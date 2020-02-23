#ifndef _dynarray_h
#define _dynarray_h

/*
A dynamic array.
'space' indicates how many elements the array can currently hold.
'length' indicates how many elements are actually in the array.
'space' must always be >= 'length'
'contents' is a pointer to an array of integers, which must be of length 'space'
*/
struct dynarray {
    int space;
    int length;
    int *contents;
};

/*
Creates a new dynamic array, containing 'length' elements,
each of which must be initialized to 0.
*/
dynarray dynarray_new(int length);

/*
Takes two arguments: an array of ints 'source', and an int 'length'.
'length' must indicate how many elements are in 'source'
Creates a new dynamic array sized to hold 'length' elements,
and containing all the elements of 'source'.
*/
dynarray dynarray_new(int source[], int length);


/*
Returns the number of elements in the dynamic array pointed to by 'arr'.
*/
int dynarray_length(dynarray *arr);

/*
Takes two arguments: a pointer to a dynamic array, 'arr'
and an integer value, 'val'.
Expands the underlying storage for 'arr' to allocate at least
enough space to hold 'val', and inserts 'val' as a new last element.
Updates 'length' to indicate how many values are now in the array.
*/
void dynarray_append(dynarray *arr, int val);

/*
Takes two arguments: a pointer to a dynamic array, 'arr'
and an integer index, 'idx.'
Returns the value of the array at index 'idx'.
*/
int dynarray_get(dynarray *arr, int idx);

/*
Takes three arguments: a pointer to a dynamic array,
an index, and a value. Sets the array element at
position 'idx' to the value 'val'.
*/
void dynarray_set(dynarray *arr, int idx, int val);

/*
Takes two arguments: a pointer to a dynamic array, 'arr'
and an integer index, 'idx.'
Returns a pointer to the element at position 'idx' of 'arr'.
*/
int *dynarray_at(dynarray *arr, int idx);

/*
Takes three arguments: a pointer to a dynamic array, 'arr'
and two integers, 'start' and 'len'.
Returns a new dynamic array of length 'len' containing copies of the
elements of 'arr' from element 'start' through element 'start' + 'len' - 1.
*/
dynarray dynarray_slice(dynarray *arr, int start, int len);

/*function to print each function*/
void dynarray_print(dynarray* arr);

#endif
