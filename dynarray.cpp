#include <assert.h>
#include <iostream>
#include "dynarray.h"


dynarray dynarray_new(int length) {
   dynarray arr;
   arr.length = length;
   arr.space = length;
   arr.contents = new int[length];
   for(int i = 0; i < length; i++){
      arr.contents[i] = 0;
   }
   return arr;
}

dynarray dynarray_new(int source[], int length) {
   dynarray arr;
   arr.length = length;
   arr.space = length;
   arr.contents = new int[length];
   for (int i =0; i < length; i++){
       // the contents of the array equal the elements of source
       arr.contents[i] = source[i];
   }
  return arr;
}

// arr points to "length" which is the length of the array
int dynarray_length(dynarray *arr) {
    return arr->length;
}

void dynarray_append(dynarray *arr, int val) {
  if(arr -> length == arr->space){
        arr->space *= 2;
        int *a = new int[arr->space];//make a new array of integers with new space
        for(int i =0; i < arr->length; i++){
            a[i] = arr->contents[i];
        }
        delete [] arr->contents; //deletes old array (frees up some memory)
        arr->contents = a; //points arr.contents to new array
        arr->contents[arr->length] = val; //add new value at the end of new array
        arr->length++;
    }
    else{
         arr->contents[arr->length] = val;
         arr->length++;
    }

}

// assert prevents any index larger than the array from being used
// arr points to the value in the contents array at 'idx'
int dynarray_get(dynarray *arr, int idx) {
    assert (idx < arr-> length);
    return arr->contents[idx];
}

// arr points to the "idx" position in the contents array
// assigning that value to "val"
void dynarray_set(dynarray *arr, int idx, int val) {
     arr->contents[idx] = val;
}

// arr points to the "idx" position of the contents array
int *dynarray_at(dynarray *arr, int idx) {
      return arr->contents+idx;
}

// a new method "obj" of length, space and contents
// are used to start the slice at the start of arr through the
// length of len
dynarray dynarray_slice(dynarray *arr, int start, int len) {
        dynarray obj;
        obj.length = len;
        obj.space = len;
        obj.contents = new int[len];
        for(int i = 0; i < len; i++){
        obj.contents[i] = arr->contents[i+start];
        }
        return obj;
}
// function to print out other functions
void dynarray_print(dynarray* arr){
    for(int i = 0; i < arr->length; i++){
        std::cout<< arr->contents[i]<< " ";
    }
    std::cout <<arr<<std::endl;
}

int main() {
	int test[] = {1, 20, 30, 40, 50, 60, 70, 80, 90};
    dynarray a = dynarray_new(test, 9);
	std::cout << dynarray_get(&a, 8) << " should be 3" << std::endl;
	dynarray s = dynarray_slice(&a,7,10);
	dynarray_append(&a,100);
	std::cout << dynarray_length(&s) << " should be 2" << std::endl;
	for (int i=0; i < dynarray_length(&a); i++) {
		std::cout << *(dynarray_at(&s,i)) << std::endl;
	}
}
