#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

/*
    Function:       printCourses
    Purpose:        prints the courses in the course collection that will occur given the given term.
    param arr:      the id representing the course that the user is trying to find, in
    param term:     the course that is to be retrieved, in
    Return:         nothing
*/
void printCourses(CourseArrayType *arr, char *term) {
    int numOfCourses = 0;
    char ddStr[MAX_STR] = "N/A";
    
    printf("\nHere are the course available for the %s term:\n",term);
    
    for (int i = 0; i <arr->size; i++){ //Iterates over the course collection array.
        if (strcmp(arr->elements[i]->term, term) == 0){
            numOfCourses++;
            convertDelDays(arr->elements[i]->delDays,&ddStr);
            
            //Course summary that is printed out.
            printf("%d  %s  %s  %c  %-10s  %s  %.2d:%.2d\n",arr->elements[i]->id,arr->elements[i]->term,arr->elements[i]->code,arr->elements[i]->section,arr->elements[i]->instructor,ddStr,arr->elements[i]->startTime.hour,arr->elements[i]->startTime.mins);
        }
    }

    //If the course collection has no classes for the specific term.
    if (numOfCourses == 0){
        printf("No courses available for this term.\n");
    }
}

/*
    Function:       convertDelDays
    Purpose:        convert the given DeliveryDaysType variable to it's appropriate string representation
    param dd:       the DeliveryDaysType variable, in
    param ddStr:    the string representation for the DeliveryDaysType variable, out
    Return:         nothing
*/
void convertDelDays(DeliveryDaysType dd, char *ddStr){
    if ((int)dd == 0){
        strcpy(ddStr,"MW");
    } else if ((int)dd == 1){
        strcpy(ddStr,"TR");
    } else if ((int)dd == 2){
        strcpy(ddStr,"WF");
    } else {
        strcpy(ddStr,"N/A");
    }
}

/*
    Function:       cleanCourses
    Purpose:        deallocates the previously dynamically allocated memory from each course in the given course collection
    param arr:      the given course collection, in-out
    Return:         nothing
*/
void cleanCourses(CourseArrayType *arr){
    for (int i = 0; i < arr->size; i++){
            free(arr->elements[i]); //Deallocating the memory.
        }
}