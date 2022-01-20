#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

/*
    Function:       addCourse
    Purpose:        adds the given course to the given course collection
    param arr:      the current course collection, in-out
    param c:        the course, in-out
    Return:         a success/failure flag
*/
int addCourse(CourseArrayType *arr, CourseType *c){
	if(arr->size < MAX_ARR){
	    arr->elements[arr->size++] = c;
	    return C_OK;
	}
	else{
	    return C_NOK;
	}
}

/*
    Function:       initCourseArray
    Purpose:        initalizes the given course collection
    param arr:      the current course collection, in-out
    Return:         nothing
*/
void initCourseArray(CourseArrayType *arr){
	arr->size = 0;
	arr->elements[MAX_ARR];
}

/*
    Function:       findCourse
    Purpose:        iterates over the given course collection to find if the given id can be found inside of it
    param arr:      the current course collection, in
    param id:       the id representing the course that the user is trying to find, in
    param c:        the course that is to be retrieved, out
    Return:         a success/failure flag
*/
int findCourse(CourseArrayType *arr, int id, CourseType **c){
    CourseType* ptr;

    for (int i = 0; i < arr->size; i++){    //Iterates over the array and compares each element's id.
        if (arr->elements[i]->id == id){
            ptr = arr->elements[i];
            *c = ptr;
            return C_OK;
        }
    }
    return C_NOK;
}