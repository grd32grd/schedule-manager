#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "defs.h"

/*
    Function:       clearSchedule
    Purpose:        resets the given schedule by setting all it's course slots to NULL values.
    param sched:    the given schedule, in-out
    Return:         nothing
*/
void clearSchedule(ScheduleType *sched){
    for (int i = 0; i < NUM_DAYS; i++){ //Iterates over the schedule's courses.
        for (int j = 0; j < NUM_SLOTS; j++){
               sched->courses[i][j] = NULL; 
        }
    }
}

/*
    Function:       computeDaysFromDel
    Purpose:        converts the given DeliveryDaysType to its two corresponding int representations
    param dd:       the DeliveryDaysType variable, in
    param d1:       the first int representation, out
    param d2:       the second int representation, out
    Return:         the success/failure flag
*/
int computeDaysFromDel(DeliveryDaysType dd, int *d1, int *d2) {
    if ((int)dd == 0){
        *d1 = 0; *d2 = 2; return C_OK;
    } else if ((int)dd == 1){
        *d1 = 1; *d2 = 3; return C_OK;
    } else if ((int)dd == 2){
        *d1 = 2; *d2 = 4; return C_OK;
    } else { 
        return C_NOK;
    }
}

/*
    Function:       computeSlotFromTime
    Purpose:        converts the given hrs and mins value to it's appropriate slot value
    param hrs:      hrs value, in
    param mins:     mins value, in
    param slot:     slot value, out
    Return:         the success/failure flag
*/
int computeSlotFromTime(int hrs, int mins, int *slot){
    if (hrs == 8 && mins == 30){
        *slot = 0; return C_OK;
    } else if (hrs == 10 && mins == 0){
        *slot = 1; return C_OK;
    } else if (hrs == 11 && mins == 30){
        *slot = 2; return C_OK;
    } else if (hrs == 13 && mins == 0){
        *slot = 3; return C_OK;
    } else if (hrs == 14 && mins == 30){
        *slot = 4; return C_OK;
    } else if (hrs == 16 && mins == 0){
        *slot = 5; return C_OK;
    } else { 
        return C_NOK;
    }
}

/*
    Function:       computeTimeFromSlot
    Purpose:        converts the given slot value to it's appropriate hrs and mins values.
    param slot:     slot value, in
    param hrs:      hrs value, out
    param mins:     mins value, out
    Return:         the success/failure flag
*/
int computeTimeFromSlot(int slot, int *hrs, int *mins){
    if (slot == 0){
        *hrs = 8; *mins = 30; return C_OK;
    } else if (slot == 1){
        *hrs = 10; *mins = 0; return C_OK;
    } else if (slot == 2){
        *hrs = 11; *mins = 30; return C_OK;
    } else if (slot == 3){
        *hrs = 13; *mins = 0; return C_OK;
    } else if (slot == 4){
        *hrs = 14; *mins = 30; return C_OK;
    } else if (slot == 5){
        *hrs = 16; *mins = 0; return C_OK;
    } else { 
        return C_NOK;
    }
}

/*
    Function:       addToSchedule
    Purpose:        adds the given course to the given schedule
    param sched:    the given schedule, in-out
    param c:        the given course, in-out
    Return:         the success/failure flag
*/
int addToSchedule(ScheduleType *sched, CourseType *c){
    int d1;
    int d2;
    int slot;

    if (computeDaysFromDel(c->delDays,&d1,&d2) == C_NOK){   //Computes the two time slots
        return C_NOK;
    } 

    if (computeSlotFromTime(c->startTime.hour,c->startTime.mins,&slot) == C_NOK){   //Computes the time slot.
        return C_NOK;
    }

    sched->courses[d1][slot] = c; //Adds the course to the two slots.
    sched->courses[d2][slot] = c;
    
    if (sched->courses[d1][slot]->code != NULL){
        return C_OK;
    } else {
        return C_NOK; 
    }
}

/*
    Function:       printSchedule
    Purpose:        prints the current schedule of courses for the given term.
    param sched:    given schedule, in-out
    param term:     given term, in-out
    Return:         nothing
*/
void printSchedule(ScheduleType *sched, char *term){
    int hrs;
    int mins;
    
    //Strings that will help create the schedule.
    char border[122];
    char bigspace[19];
    char space[11];
    char minispace[7];
    char endspace[12];
    
    memset(border, '-', 122);
    border[121] = '\0';
    memset(bigspace, ' ', 19);
    bigspace[18] = '\0';
    memset(space, ' ', 11);
    space[10] = '\0';
    memset(minispace, ' ', 7);
    minispace[6] = '\0';
    memset(endspace, ' ', 12);
    endspace[11] = '\0';
    

    //Top border that illustrates the top of the schedule with the days of the week.
    printf("\nSchedule for the %s term:\n",term);
    printf("%s\n",border);
    printf("|%sMON%sTUE%sWED%sTHU%sFRI%s    |\n",bigspace,bigspace,bigspace,bigspace,bigspace,space);
    
    for (int i = 0; i < NUM_SLOTS; i++){
        
        printf("%s\n",border);
        
        //First line that prints each course's term and section.
        computeTimeFromSlot(i,&hrs,&mins);
        printf("| %.2d:%.2d |%s",hrs,mins,minispace);
        for (int j = 0; j < NUM_DAYS; j++){
            char courseStr[MAX_STR];
            
            if (sched->courses[j][i] != NULL){
                snprintf(courseStr, sizeof(courseStr), "%s %c",sched->courses[j][i]->code,sched->courses[j][i]->section);
            } else {
                snprintf(courseStr, sizeof(courseStr), "%11s","");
            }
            printf("%s%s",courseStr,space);
            
        }
        printf("|\n");
        
        //Second line that prints each course's instructor.
        printf("|       |%s",minispace);
        for (int k = 0; k < NUM_DAYS; k++){
            char instructorStr[MAX_STR];
            
            if (sched->courses[k][i] != NULL){
                snprintf(instructorStr, sizeof(instructorStr), "%s", sched->courses[k][i]->instructor);
            } else {
                snprintf(instructorStr, sizeof(instructorStr), "%11s","");
            }
            printf("%-11s%s",instructorStr,space);
            
        }
        printf("|\n");
    }
 
    //Bottom border for the schedule.
    printf("%s\n",border);
}
